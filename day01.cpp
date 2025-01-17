#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

int get_fuel(int mass) {
  int total_fuel = 0;
  while (mass > 0) {
    int required_fuel = mass / 3 - 2;
    total_fuel += std::max(required_fuel, 0);
    mass = required_fuel;
  }
  return total_fuel;
}

int main() {
  std::ifstream file("inputs/d01");
  if (!file.is_open()) {
    std::cerr << "Unable to open file!" << std::endl;
    return 1;
  }

  std::string line;
  std::regex re("\\d+");  // Regular expression to match integers

  int total_fuel{0};
  int part_2{0};
  while (std::getline(file, line)) {
    std::vector<int> line_nums;
    std::sregex_iterator begin(line.begin(), line.end(), re), end;

    for (auto it = begin; it != end; ++it) {
      line_nums.push_back(std::stoi(it->str()));
    }

    total_fuel += line_nums[0] / 3 - 2;
    part_2 += get_fuel(line_nums[0]);
  }
  file.close();

  std::cout << total_fuel << std::endl;
  std::cout << part_2 << std::endl;

  return 0;
}
