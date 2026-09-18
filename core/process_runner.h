#pragma once
#include <string>
#include <vector>

struct ProcessResult {
    int exit_code = -1;
    std::string output;
};

ProcessResult run_process(const std::string& executable, const std::vector<std::string>& args);