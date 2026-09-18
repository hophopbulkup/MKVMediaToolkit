#include "remux.h"

static const std::string MKVMERGE_PATH = "bin/mkvtools/mkvmerge.exe";

RemuxResult remux(const std::string& input_path, const std::string& output_path) {
    std::vector<std::string> args = {
        "-o", output_path,
        input_path
    };

    return run_process(MKVMERGE_PATH, args);
}