#include <iostream>
#include "core/process_runner.h"
#include "operations/remux.h"

int main() {
    RemuxResult result = remux("input.mkv", "output.mp4");

    std::cout << "Exit code: " << result.exit_code << "\n";
    std::cout << "--- Output ---\n" << result.output << "\n";

    if (result.exit_code == 0) {
        std::cout << "FFmpeg encontrado a funcionar!\n";
    } else {
        std::cout << "Nao foi possivel correr o FFmpeg.";
    }

    return 0;
}