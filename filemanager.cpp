#include "filemanager.h"
#include <fstream>
#include <stdexcept>

std::vector<char> FileManager::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);
    
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    std::vector<char> buffer(size);
    file.read(buffer.data(), size);
    return buffer;
}

void FileManager::writeFile(const std::string& filename, const std::vector<char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Cannot create file: " + filename);
    file.write(data.data(), data.size());
}

bool FileManager::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}