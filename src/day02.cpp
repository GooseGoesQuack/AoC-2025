#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <numeric>

std::vector<std::string> readFile(const std::string &filename);
void part1(const std::vector<std::string>& lines);
void part2(const std::vector<std::string>& lines);

int main() {
    std::vector<std::string> lines = readFile("../input/day02.txt");
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
    while (std::getline(file, line, ',')) {
        lines.push_back(line);
    }
    return lines;
}

void part1(const std::vector<std::string> &lines) {
    std::vector<long long> invalid;
    for (const auto& line : lines) {
        size_t dashpos = line.find('-');
        std::pair<long, long> range = {std::stol(line.substr(0, dashpos)), std::stol(line.substr(dashpos+1))};
        std::cerr << range.first << "-" << range.second << "\n";
        for (long long id=range.first; id<=range.second; id++) {
            int length = std::to_string(id).length();
            if (length%2==0 && std::to_string(id).substr(0, length/2)==std::to_string(id).substr(length/2)) {
                invalid.push_back(id);
            }
        }
    }
    std::ranges::sort(invalid);
    invalid.erase(std::unique(invalid.begin(), invalid.end()), invalid.end());
    long long sum = std::accumulate(invalid.begin(), invalid.end(), 0LL);
    std::cout << "sum: " << sum << "\n";      
}

void part2(const std::vector<std::string> &lines) {
    std::vector<long long> invalid;
    for (const auto& line : lines) {
        size_t dashpos = line.find('-');
        std::pair<long, long> range = {std::stol(line.substr(0, dashpos)), std::stol(line.substr(dashpos+1))};
        
        for (long long id=range.first; id<=range.second; id++) {
            int length = std::to_string(id).length();
            for (int mult=2; mult<=length; mult++) {
                if (length%mult==0) {
                    bool allsame = true;
                    for (int i=1; i<=mult-1; i++) {
                        if (std::to_string(id).substr((i-1)*length/mult, length/mult)!=std::to_string(id).substr((i)*length/mult, length/mult)) {
                            allsame = false;
                        }
                    }
                    if (allsame) {
                        invalid.push_back(id);
                    }
                        
                }

            }
        }
    }
    std::ranges::sort(invalid);
    invalid.erase(std::unique(invalid.begin(), invalid.end()), invalid.end());
    long long sum = std::accumulate(invalid.begin(), invalid.end(), 0LL);
    std::cout << "sum: " << sum << "\n";
}
     
