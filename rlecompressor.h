#pragma once
#include <vector>
#include <cstdint>
//best used for images for example its simple algo but not really for text 
class RLECompressor {
public:
    static std::vector<uint8_t> compress(const std::vector<char>& data);
    static std::vector<char> decompress(const std::vector<uint8_t>& compressedData);
};