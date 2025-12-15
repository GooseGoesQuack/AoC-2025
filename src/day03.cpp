#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <numeric>

std::vector<std::string> readFile(const std::string &filename);
// void part1(const std::vector<std::string> &lines);
void part2(const std::vector<std::string> &lines);

int main() {
    std::vector<std::string> lines = readFile("../input/day03.txt");
    // part1(lines);
    part2(lines);
    return 0;
}

std::vector<std::string> readFile(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return lines;
    }
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
    
}

void part1(const std::vector<std::string> &lines) {
    int joltage = 0;
    for (const auto &line : lines) {
        const std::string &line2 = line.front() + line + line.back();
        int max = 0;
        int num_pairs = line.size()/2;
        
        for (std::size_t i=0; i<num_pairs; ++i) {
            
            int num = std::stoi(line.substr(i,2));
            if (num > max) {
                max = num;
            }
            
        }
        
        for (std::size_t i=0; i<num_pairs+1; ++i) {
            int num = std::stoi(line2.substr(i,2));
            if (num > max) {
                max = num;
            }
        }
        
        joltage += max;
        std::cerr << max << "\n";
    }
    std::cout << joltage << "\n";
} 

void part2(const std::vector<std::string> &lines) {
    long joltage = 0;
    for (const auto &line : lines) {
        std::string line_joltage = "";
        auto first = line.begin();
        auto last = line.end() - 11;
        for (size_t i=0; i<=11; ++i) {
            auto it = std::ranges::max_element(first, last); 
            line_joltage += *it;
            first = std::next(it);
            ++last;
        }
        joltage += std::stol(line_joltage);
    }
    std::cout << "joltage: " << joltage << "\n";
}