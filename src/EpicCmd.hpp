#ifndef _EPIC_CMD
#define _EPIC_CMD

// #include "cmd_def.hpp"

#include "tcl.h"

#include <iostream>
#include <string>
#include <vector>

class EpicCmd {
 protected:
  Tcl_Interp *interp = NULL;

 public:
  EpicCmd() = default;

  virtual ~EpicCmd() = default;

  virtual void bind() = 0;

 public:
  void init() {
    if (interp == NULL) {
      interp = Tcl_CreateInterp();
    }
  }

  void call(const std::string &command) {
    init();
    std::vector<std::string> args = parse(command);
    bind();
    execute(args);
    shutdown();
  }

  std::vector<std::string> parse(const std::string &command) {
    std::vector<std::string> args;
    args.push_back(command);
    return args;
  }

  void execute(std::vector<std::string> args) {
    const std::string filename = args[0];

    if (Tcl_EvalFile(interp, filename.c_str()) != TCL_OK) {
      //printf("error: %s\n", Tcl_GetStringResult(interp));
      std::string error_msg = Tcl_GetStringResult(interp);
      error_msg = "TCL ERROR: " + error_msg;
      //std::cerr << error_msg << std::endl;
      throw error_msg;
    }

  }

  void shutdown() {
    if (interp != NULL) {
      Tcl_DeleteInterp(interp);
      Tcl_Finalize();
      interp = NULL;
    }
  }
};

#endif
