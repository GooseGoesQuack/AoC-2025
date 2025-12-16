#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <deque>

struct Part1Output {
    std::deque<std::string> lines;
    int count;
};

std::deque<std::string> readFile(const std::string &filename);
Part1Output part1(std::deque<std::string> lines);
void part2(std::deque<std::string> lines);

int main()
{
    std::deque<std::string> lines = readFile("../input/day04.txt");
    part1(lines);
    part2(lines);
    return 0;
}

std::deque<std::string> readFile(const std::string &filename) {
    std::ifstream file(filename);
    std::deque<std::string> lines;
    std::string padding (142, '.');
    lines.push_back(padding);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return lines;
    }
    while (std::getline(file, line)) {
        lines.push_back("."+line+".");
    }
    lines.push_back(line);
    return lines;
    
}

Part1Output part1(std::deque<std::string> lines) {
    std::string padding (142, '.');
    int count = 0;
    // One of many part 2 modifications:
    std::deque<std::string> new_lines;
    new_lines.push_back(padding);

    for (int line_num=1; line_num<141; ++line_num) {
        std::string line = lines[line_num];
        std::string next_line = lines[line_num+1];
        std::string prev_line = lines[line_num-1];
        std::string new_line = "";
        for (int i=1; i<141; ++i) {
            if (line[i]=='@') {
                std::string adjacent = "";
                adjacent += line[i-1];
                adjacent += line[i+1];
                adjacent += prev_line.substr(i-1, 3);
                adjacent += next_line.substr(i-1, 3);
                if (std::count(adjacent.begin(), adjacent.end(), '@') < 4) {
                    ++count;
                    new_line += 'x';
                } else {
                    new_line += '@';
                }
            } else {
                new_line += '.';
            }
        }
        new_lines.push_back("."+new_line+".");
    }
    new_lines.push_back(padding);
    std::cout << count << "\n";
    
    return Part1Output{new_lines, count};
}

void part2(std::deque<std::string> lines) {
    int count = 0;
    int it_count = 1;
    while (it_count > 0) { 
        Part1Output r = part1(lines);
        it_count = r.count;
        lines = std::move(r.lines);
        count += it_count;
    }
    if (it_count == 0) {
        for (auto &line : lines) {
            // std::cerr << line << std::endl;
        }
    }
    std::cout << count << "\n";
}