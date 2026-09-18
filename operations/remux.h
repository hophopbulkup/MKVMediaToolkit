#pragma once
#include <string>
#include "../core/process_runner.h"

using RemuxResult = ProcessResult;

RemuxResult remux(const std::string& input_path, const std::string& output_path);