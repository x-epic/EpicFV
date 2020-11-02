#ifndef _EPIC_SOLVER_CMD
#define _EPIC_SOLVER_CMD

#include <stdio.h>

#include <string>
#include <unordered_map>
#include "EpicCmd.hpp"

class EpicSolverCmd final : public EpicCmd {
 private:
  static std::unordered_map<std::string, std::string> solver_res_map;
  static std::vector<std::string> engine_arr;
  static std::vector<std::string> script_arr;
  static std::vector<std::string> file_arr;
  static std::string filelist;
  static std::unordered_map<std::string, std::string> macro_map;
  static std::vector<std::string> verilog_file_arr;
  // name of top-level clock input
  static std::string m_clock_name;
  // name of top-level reset input(active high)
  static std::string m_reset_name;
  // number of cycles reset should stay active
  static std::string m_cycle_reset_num;
  // number of cycles to simulate
  static std::string m_cycle_simulate_num;
  static bool is_sim_run;
  static bool m_reset_polarity;

 public:
  EpicSolverCmd() = default;

  ~EpicSolverCmd() = default;

  static int set_mode(ClientData clientData, Tcl_Interp *interp, int argc,
                      Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string mode = arg1;
    solver_res_map.insert(std::make_pair("mode", mode));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_depth(ClientData clientData, Tcl_Interp *interp, int argc,
                       Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "int1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string depth = arg1;
    solver_res_map.insert(std::make_pair("depth", depth));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_expect(ClientData clientData, Tcl_Interp *interp, int argc,
                        Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string except = arg1;
    solver_res_map.insert(std::make_pair("except", except));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_timeout(ClientData clientData, Tcl_Interp *interp, int argc,
                         Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "int1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string timeout = arg1;
    solver_res_map.insert(std::make_pair("timeout", timeout));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_wait(ClientData clientData, Tcl_Interp *interp, int argc,
                      Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string wait = arg1;
    solver_res_map.insert(std::make_pair("wait", wait));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_aigsmt(ClientData clientData, Tcl_Interp *interp, int argc,
                        Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string aigsmt = arg1;
    solver_res_map.insert(std::make_pair("aigsmt", aigsmt));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_tbtop(ClientData clientData, Tcl_Interp *interp, int argc,
                       Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string tbtop = arg1;
    solver_res_map.insert(std::make_pair("tbtop", tbtop));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_smtc(ClientData clientData, Tcl_Interp *interp, int argc,
                      Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string smtc = arg1;
    solver_res_map.insert(std::make_pair("smtc", smtc));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_skip(ClientData clientData, Tcl_Interp *interp, int argc,
                      Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "string1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    std::string skip = arg1;
    solver_res_map.insert(std::make_pair("skip", skip));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int set_append(ClientData clientData, Tcl_Interp *interp, int argc,
                        Tcl_Obj *const argv[]) {
    if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "int1");
      return TCL_ERROR;
    }

    // Tcl_Obj* result = NULL;

    char *arg1 = Tcl_GetString(argv[1]);

    const std::string append = arg1;
    solver_res_map.insert(std::make_pair("append", append));

    // result = Tcl_NewStringObj(arg1, strlen(arg1));

    // Tcl_SetObjResult(interp, result);

    return TCL_OK;
  }

  static int chformal(ClientData clientData, Tcl_Interp *interp, int argc,
                      Tcl_Obj *const argv[]) {
    std::string chformal_val = "";
    for (int i = 1; i != argc; ++i) {
      const std::string str_tmp = Tcl_GetString(argv[i]);
      chformal_val += str_tmp + " ";
    }
    solver_res_map.insert(std::make_pair("chformal_val", chformal_val));

    return TCL_OK;
  }

  static int set_engines(ClientData clientData, Tcl_Interp *interp, int argc,
                         Tcl_Obj *const argv[]) {
    std::string engine = "";
    for (int i = 1; i != argc; ++i) {
      const std::string str_tmp = Tcl_GetString(argv[i]);
      engine += str_tmp + " ";
    }
    engine_arr.push_back(engine);

    return TCL_OK;
  }

  static int set_script(ClientData clientData, Tcl_Interp *interp, int argc,
                        Tcl_Obj *const argv[]) {
    std::string script = "";
    for (int i = 1; i != argc; ++i) {
      const std::string str_tmp = Tcl_GetString(argv[i]);
      script += str_tmp + " ";
    }
    script_arr.push_back(script);

    return TCL_OK;
  }

  static int set_files(ClientData clientData, Tcl_Interp *interp, int argc,
                       Tcl_Obj *const argv[]) {
    std::string file = "";
    for (int i = 1; i != argc; ++i) {
      const std::string str_tmp = Tcl_GetString(argv[i]);
      file += str_tmp + " ";
    }
    file_arr.push_back(file);

    return TCL_OK;
  }

  static std::vector<std::string> split_string_by_space(std::string src) {
    src += " ";
    std::vector<std::string> rt;
    std::string split_str;
    for (int i = 0; i < src.length(); ++i) {
      char currentCh = src[i];
      if (currentCh != ' ') {
        split_str += currentCh;
      } else {
        if (!split_str.empty()) {
          rt.emplace_back(split_str);
          split_str = "";
        }
      }
    }
    return std::move(rt);
  }

  static bool get_macro_value(std::vector<std::string> &macro_value) {
    if (macro_value.size() != 1 && macro_value.size() != 3) {
      return false;
    }
    if (macro_value.size() == 1) {
      macro_map.insert(std::make_pair(macro_value[0], ""));
    } else {
      macro_map.insert(std::make_pair(macro_value[0], macro_value[2]));
    }
    std::vector<std::string>().swap(macro_value);
    return true;
  }

  static int read_file(ClientData clientData, Tcl_Interp *interp, int argc,
                       Tcl_Obj *const argv[]) {
    int filelist_index = argc - 1;
    int top_index = argc - 1;
    int cmopts_index = -1;
    std::vector<int> reserve_index;
    std::string str_tmp;
    bool pre_is_option = false;
    for (int i = 1; i != argc; ++i) {
      str_tmp = Tcl_GetString(argv[i]);
      if (str_tmp == "-f") {
        filelist_index = i;
        pre_is_option = true;
      } else if (str_tmp == "-cmopts") {
        cmopts_index = i;
        pre_is_option = true;
      } else if (str_tmp == "-top") {
        top_index = i;
        pre_is_option = true;
      } else {
        if (!pre_is_option) {
          reserve_index.push_back(i);
        }
        pre_is_option = false;
      }
    }
    if (top_index == argc - 1 || cmopts_index == argc - 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "-cmopts [macro] -top [top_module] ");
      return TCL_ERROR;
    }
    if (filelist_index != argc - 1) {
      filelist = Tcl_GetString(argv[filelist_index + 1]);
    }
    std::string top_module = Tcl_GetString(argv[top_index + 1]);
    solver_res_map.insert(std::make_pair("top_module", top_module));
    for (auto index : reserve_index) {
      str_tmp = Tcl_GetString(argv[index]);
      verilog_file_arr.push_back(str_tmp);
    }
    if (cmopts_index > 0) {
      std::string cmopts_param = Tcl_GetString(argv[cmopts_index + 1]);
      std::vector<std::string> split_result =
          split_string_by_space(cmopts_param);
      if (split_result.at(0) != "+define") {
        return TCL_ERROR;
      }
      std::vector<std::string> macro_value;
      for (int i = 1; i < split_result.size(); ++i) {
        str_tmp = split_result.at(i);
        if (str_tmp == "+define") {
          if (!get_macro_value(macro_value)) {
            return TCL_ERROR;
          }
        } else {
          std::string combine_str = "";
          for (int j = 0; j < str_tmp.length(); ++j) {
            if (str_tmp[j] == '=') {
              if ((combine_str.empty() && macro_value.size() == 0) ||
                  macro_value.size() >= 2) {
                return TCL_ERROR;
              }
              if (!combine_str.empty()) {
                macro_value.push_back(combine_str);
                combine_str = "";
              }
              macro_value.push_back("=");
            } else {
              combine_str += str_tmp[j];
            }
          }
          if (!combine_str.empty()) {
            macro_value.push_back(combine_str);
          }
          if (macro_value.size() > 3) {
            return TCL_ERROR;
          }
        }
      }
      if (!get_macro_value(macro_value)) {
        return TCL_ERROR;
      }
    }
    return TCL_OK;
  }

  static int create_clock(ClientData clientData, Tcl_Interp *interp, int argc,
                          Tcl_Obj *const argv[]) {
    if (argc != 3) {
      return TCL_ERROR;
    }
    std::string str_tmp = Tcl_GetString(argv[1]);
    if (str_tmp != "-clock") {
      return TCL_ERROR;
    }
    m_clock_name = Tcl_GetString(argv[2]);
    return TCL_OK;
  }

  static int create_rst(ClientData clientData, Tcl_Interp *interp, int argc,
                        Tcl_Obj *const argv[]) {
    if (argc != 3) {
      return TCL_ERROR;
    }
    std::string str_tmp = Tcl_GetString(argv[1]);
    if (str_tmp == "-rst") {
      m_reset_polarity = true;
    } else if (str_tmp == "-rstn") {
      m_reset_polarity = false;
    } else {
      return TCL_ERROR;
    }
    m_reset_name = Tcl_GetString(argv[2]);
    return TCL_OK;
  }

  static int sim_run(ClientData clientData, Tcl_Interp *interp, int argc,
                     Tcl_Obj *const argv[]) {
    is_sim_run = true;
    int n_index = argc - 1;
    int rst_len_index = argc - 1;
    std::string str_tmp;
    for (int i = 1; i != argc; ++i) {
      str_tmp = Tcl_GetString(argv[i]);
      if (str_tmp == "-n") {
        n_index = i;
      } else if (str_tmp == "-rstlen") {
        rst_len_index = i;
      }
    }
    if (n_index != argc - 1) {
      m_cycle_simulate_num = Tcl_GetString(argv[n_index + 1]);
    }
    if (rst_len_index != argc - 1) {
      m_cycle_reset_num = Tcl_GetString(argv[rst_len_index + 1]);
    }
    return TCL_OK;
  }

  void bind() {
    Tcl_CreateObjCommand(interp, "set_mode", set_mode, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_depth", set_depth, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_expect", set_expect, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_timeout", set_timeout, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_wait", set_wait, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_aigsmt", set_aigsmt, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_tbtop", set_tbtop, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_smtc", set_smtc, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_skip", set_skip, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_append", set_append, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_engines", set_engines, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_script", set_script, NULL, NULL);
    Tcl_CreateObjCommand(interp, "set_files", set_files, NULL, NULL);
    Tcl_CreateObjCommand(interp, "read_file", read_file, NULL, NULL);
    Tcl_CreateObjCommand(interp, "chformal", chformal, NULL, NULL);
    Tcl_CreateObjCommand(interp,"create_clock",create_clock,NULL,NULL);
    Tcl_CreateObjCommand(interp,"create_rst",create_rst,NULL,NULL);
    Tcl_CreateObjCommand(interp,"sim_run",sim_run,NULL,NULL);

  }

  static std::unordered_map<std::string, std::string> get_solver_res_map() {
    return solver_res_map;
  }

  static std::vector<std::string> get_engines() { return engine_arr; }

  static std::vector<std::string> get_scripts() { return script_arr; }

  static std::vector<std::string> get_files() { return file_arr; }

  static std::string get_filelist() { return filelist; }

  static std::unordered_map<std::string, std::string> &get_macro_map() {
    return macro_map;
  }
  static std::vector<std::string> get_verl_files() { return verilog_file_arr; }
  static bool get_sim_param(std::string &clock_name, std::string &reset_name,
                            std::string &cycle_reset_num,
                            std::string &cycle_simulate_num,
                            bool &reset_polarity) {
    /*if (m_clock_name.empty() || m_reset_name.empty()) {
      return false;
    }*/ // check should seperate
    clock_name = m_clock_name;
    reset_name = m_reset_name;
    cycle_reset_num = m_cycle_reset_num;
    cycle_simulate_num = m_cycle_simulate_num;
    reset_polarity = m_reset_polarity;
    return true;
  }
  static bool get_sim_run() { return is_sim_run; }
};

#endif
