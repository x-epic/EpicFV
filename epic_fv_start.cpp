#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

#include "src/EpicSolverCmd.hpp"
#include "util/json.hpp"

using json_t = nlohmann::json;

std::unordered_map<std::string, std::string> EpicSolverCmd::solver_res_map;
std::vector<std::string> EpicSolverCmd::engine_arr;
std::vector<std::string> EpicSolverCmd::script_arr;
std::vector<std::string> EpicSolverCmd::file_arr;
std::string EpicSolverCmd::filelist;
std::vector<std::string> EpicSolverCmd::verilog_file_arr;
std::unordered_map<std::string, std::string> EpicSolverCmd::macro_map;
std::string EpicSolverCmd::m_clock_name;
std::string EpicSolverCmd::m_reset_name;
std::string EpicSolverCmd::m_cycle_reset_num;
std::string EpicSolverCmd::m_cycle_simulate_num;
bool EpicSolverCmd::is_sim_run = false;
bool EpicSolverCmd::m_reset_polarity = false;
int main(int argc, char **argv) {
  try {
    std::string epicfv_home = getenv("EPICFV_HOME");
    if (epicfv_home.empty()) {
      throw "ERROR: cannot find env EPICFV_HOME!";
    }
    std::string tools_dir = epicfv_home + "/binary";
    std::string yosys = tools_dir + "/bin/yosys";
    std::string abc = tools_dir + "/bin/yosys-abc";
    std::string smtbmc = tools_dir + "/bin/yosys-smtbmc";
    std::string avy = tools_dir + "/bin/avy";
    std::string btormc = tools_dir + "/bin/btormc";
    std::string btorsim = tools_dir + "/bin/btorsim";

    setenv("TOOLS_DIR", tools_dir.c_str(), 1);
    setenv("YOSYS", yosys.c_str(), 1);
    setenv("ABC", abc.c_str(), 1);
    setenv("SMTBMC", smtbmc.c_str(), 1);
    setenv("AVY", avy.c_str(), 1);
    setenv("BTORMC", btormc.c_str(), 1);
    setenv("BTORSIM", btorsim.c_str(), 1);

    std::string mpirun = tools_dir + "/share/openmpi/bin/orterun";  //"mpirun";

    if (argc < 3) {
      throw "ERROR: missing Tclfile";
    }
    std::string process_num = argv[1];

    int pn = std::stoi(process_num) + 1;

    std::string tclfile = argv[2];

    struct stat fileStat;
    if ((stat(tclfile.c_str(), &fileStat) != 0) || !S_ISREG(fileStat.st_mode)) {
      throw "ERROR: cannot find tclfile";
    }

    EpicSolverCmd solver_cmd;
    solver_cmd.call(tclfile);

    std::unordered_map<std::string, std::string> res_map =
      solver_cmd.get_solver_res_map();
    std::vector<std::string> engine_arr = solver_cmd.get_engines();
    std::vector<std::string> script_arr = solver_cmd.get_scripts();
    std::vector<std::string> file_arr = solver_cmd.get_files();
    const std::string filelist = solver_cmd.get_filelist();
    std::unordered_map<std::string, std::string> marco_map = solver_cmd.get_macro_map();
    std::vector<std::string> verilog_file_arr = solver_cmd.get_verl_files();
    bool is_sim_run = solver_cmd.get_sim_run();
    std::string clock_name;
    std::string reset_name;
    std::string cycle_reset_num;
    std::string cycle_simulate_num;
    bool reset_polarity = true;
    solver_cmd.get_sim_param(clock_name, reset_name, cycle_reset_num, cycle_simulate_num, reset_polarity);

    json_t j;
    j["res_map"] = res_map;
    j["engine_arr"] = engine_arr;
    j["script_arr"] = script_arr;
    j["file_arr"] = file_arr;
    j["filelist"] = filelist;
    j["marco_map"] = marco_map;
    j["verilog_file_arr"] = verilog_file_arr;
    j["is_sim_run"] = is_sim_run;
    j["clock_name"] = clock_name;
    j["reset_name"] = reset_name;
    j["cycle_reset_num"] = cycle_simulate_num;
    j["cycle_simulate_num"] = cycle_simulate_num;
    j["reset_polarity"] = reset_polarity;

    const std::string json_str = j.dump();

    std::ofstream fout(".tcl.json");
    if (fout) {
      fout << json_str;
      fout.close();
      fout.clear();
    }

    std::string cmdline = mpirun + " --oversubscribe -x LD_LIBRARY_PATH -np " +
                          std::to_string(pn) + " " + tools_dir +
                          "/epic_fv_bin -f -b " + tclfile;
    system(cmdline.c_str());
  } catch (const char *msg) {
    std::cerr << msg << std::endl;
  } catch (const std::string &str) {
    std::cerr << str << std::endl;
  }
  struct stat fileStat;
  if ((stat(".tcl.json", &fileStat) == 0) && S_ISREG(fileStat.st_mode) && !getenv("EPICFV_INT_DEBUG")) {
    system("rm .tcl.json");
  }

}
