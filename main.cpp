#include <iostream>
#include <string>
#include <vector>
#include "filemanager.h"
#include "rlecompressor.h"

void showHelp() {
    std::cout << "Simple Zipper Tool\n"
              << "Usage:\n"
              << "  zippertool c <input> <output> - Compress file\n"
              << "  zippertool d <input> <output> - Decompress file\n";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        showHelp();
        return 1;
    }

    try {
        std::string mode = argv[1];
        std::string inputFile = argv[2];
        std::string outputFile = argv[3];

        if (!FileManager::fileExists(inputFile)) {
            std::cerr << "Error: Input file not found\n";
            return 1;
        }

        if (mode == "c") {
            auto data = FileManager::readFile(inputFile);
            auto compressed = RLECompressor::compress(data);
            FileManager::writeFile(outputFile, 
                std::vector<char>(compressed.begin(), compressed.end()));
            std::cout << "File compressed successfully. Size: " 
                      << compressed.size() << " bytes\n";
        }
        else if (mode == "d") {
            auto compressedData = FileManager::readFile(inputFile);
            std::vector<uint8_t> compressed(compressedData.begin(), compressedData.end());
            auto decompressed = RLECompressor::decompress(compressed);
            FileManager::writeFile(outputFile, decompressed);
            std::cout << "File decompressed successfully. Size: " 
                      << decompressed.size() << " bytes\n";
        }
        else {
            showHelp();
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}