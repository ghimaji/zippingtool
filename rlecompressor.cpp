#include "rlecompressor.h"
#include <stdexcept>

std::vector<uint8_t> RLECompressor::compress(const std::vector<char>& data) {
    std::vector<uint8_t> compressed;
    
    if (data.empty()) return compressed;
    
    char current = data[0];
    uint8_t count = 1;
    
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] == current && count < 255) {
            count++;
        } else {
            compressed.push_back(count);
            compressed.push_back(static_cast<uint8_t>(current));
            current = data[i];
            count = 1;
        }
    }

    compressed.push_back(count);
    compressed.push_back(static_cast<uint8_t>(current));
    
    return compressed;
}

std::vector<char> RLECompressor::decompress(const std::vector<uint8_t>& compressedData) {
    std::vector<char> decompressed;
    
    if (compressedData.size() % 2 != 0) {
        throw std::runtime_error("Invalid compressed data format");
    }
    
    for (size_t i = 0; i < compressedData.size(); i += 2) {
        uint8_t count = compressedData[i];
        char value = static_cast<char>(compressedData[i+1]);
        
        for (uint8_t j = 0; j < count; j++) {
            decompressed.push_back(value);
        }
    }
    
    return decompressed;
}