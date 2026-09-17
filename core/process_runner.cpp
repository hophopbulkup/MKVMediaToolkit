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

ProcessResult run_process(const std::string& executable, const std::vector<std::string>& args) {
    ProcessResult result;
    std::string cmd = build_command_line(executable, args);

    FILE* pipe = POPEN(cmd.c_str(), "r");
    if (!pipe) {
        result.exit_code = -1;
        result.output = "Falha ao iniciar o processo: " + executable;
        return result;
    }

    std::array<char, 4096> buffer;
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
        result.output += buffer.data();
    }
}