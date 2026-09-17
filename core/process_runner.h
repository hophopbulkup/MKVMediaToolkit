#pragma once
#include <string>
#include <vector>

struct ProcessResult {
    int exit_code = -1;
    std::string output;
};
