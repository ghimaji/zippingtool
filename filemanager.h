#pragma once
#include <string>
#include <vector>

class FileManager {
public:
    static std::vector<char> readFile(const std::string& filename);
    static void writeFile(const std::string& filename, const std::vector<char>& data);
    static bool fileExists(const std::string& filename);
};