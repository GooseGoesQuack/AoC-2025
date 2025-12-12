#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> readFile(const std::string& filename);
void part1(const std::vector<std::string>& lines);
void part2(const std::vector<std::string>& lines);

int main()
{  
    std::vector<std::string> lines = readFile("../input/day01.txt");
    part1(lines);
    part2(lines);
    return 0;
}

std::vector<std::string> readFile(const std::string& filename){
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
            zcount++;
        }
    }
    std::cout << zcount << "\n";
}

void part2(const std::vector<std::string>& lines)
{
    int zcount = 0;
    int pointer = 50;

    for (const auto& line : lines) {
        int rot = std::stoi(line.substr(1));
        zcount += rot/100;
        rot %= 100;
        if (line[0] == 'L') {
            if (pointer == 0) {
                zcount--;
            }
            pointer -= rot;
            if (pointer <= 0) {
                zcount++;
            }
            pointer = (100+pointer) % 100;
        } else {
            pointer += rot;
            if (pointer > 99) {
                zcount++;
            }
            pointer %= 100;
        }
    }
    std::cout << zcount << "\n";    
}

