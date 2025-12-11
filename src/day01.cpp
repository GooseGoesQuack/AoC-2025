#include <iostream>
#include <fstream>
#include <string>

std::vector<std::string> readFile(const std::string& filename);
void part1(const std::vector<std::string>& lines);
void part2(const std::vector<std::string>& lines);

int main()
{  
    std::vector<std::string> lines = readFile("../input/day01.txt");
    part1(lines);
    part2(lines);
}

std::vector<std::string> readFile(const std::string& filename){
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Unable to open " << filename << ".\n";
        return lines;
    }
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

void part1(const std::vector<std::string>& lines)
{
    int zcount = 0;
    int pointer = 50;

    for (const auto& line : lines) {
        int rot = std::stoi(line.substr(1));
        if (line[0] == 'L') {
            rot *= -1;
        }
        pointer += rot;
        pointer %= 100;
        if (pointer == 0) {
            zcount += 1;
        }
    }
    std::cout << zcount << "\n";
}

void part2(const std::vector<std::string>& lines)
{
    
}

