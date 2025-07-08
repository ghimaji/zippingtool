#pragma once
#include <vector>
#include <map>
#include <queue>
#include <cstdint>

struct HuffmanNode {
    uint8_t byte;
    size_t frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(uint8_t b, size_t freq) 
        : byte(b), frequency(freq), left(nullptr), right(nullptr) {}
    
    ~HuffmanNode() {
        delete left;
        delete right;
    }
};

class HuffmanCompressor {
public:
    static std::vector<uint8_t> compress(const std::vector<uint8_t>& data);
    static std::vector<uint8_t> decompress(const std::vector<uint8_t>& compressedData);

private:

    static void buildFrequencyTable(const std::vector<uint8_t>& data, 
                                  std::map<uint8_t, size_t>& frequencyTable);
    static HuffmanNode* buildHuffmanTree(const std::map<uint8_t, size_t>& frequencyTable);
    static void buildCodeTable(HuffmanNode* root, std::string code, 
                             std::map<uint8_t, std::string>& codeTable);

};