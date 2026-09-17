#include "process_runner.h"
#include <cstdio>
#include <array>
#include <stdexcept>

#ifdef _WIN32
    #define POPEN _popen
    #define PCLOSE _pclose
#else
    #define POPEN popen
    #define PCLOSE pclose
#endif

static std::string build_command_line(const std::string& executable, const std::vector<std::string>& args) {
    std::string cmd = "\"" + executable + "\"";
    for (const auto& arg : args) {
        cmd += " \"" + arg + "\"";
    }
    cmd += " 2>&1";
    return cmd;
}