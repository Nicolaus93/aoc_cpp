#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>


int solve(std::vector<int> nums, int noun, int verb, bool debug = false) {
    nums[1] = noun;
    nums[2] = verb;

    size_t idx = 0;
    while (nums[idx] != 99) {
        int idx1 = nums[idx + 1];
        int idx2 = nums[idx + 2];
        int idx3 = nums[idx + 3];
        switch (nums[idx])
        {
        case 1:
            nums[idx3] = nums[idx1] + nums[idx2];
            break;
        case 2:
            nums[idx3] = nums[idx1] * nums[idx2];
            break;
        default:
            throw std::runtime_error("Unsupported operation in nums at index: " + std::to_string(idx));;
        }
        idx += 4;
        if (debug) {
            for (auto n : nums) {
                std::cout << n << ",";
            }
            std::cout << "\n";
        }
    }
    return nums[0];
}


int main() {
    std::ifstream file("inputs/d02");
    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    std::string line;
    std::regex re("\\d+"); // Regular expression to match integers

    while (std::getline(file, line)) {
        std::vector<int> line_nums;
        std::sregex_iterator begin(line.begin(), line.end(), re), end;

        for (auto it = begin; it != end; ++it) {
            line_nums.push_back(std::stoi(it->str()));
        }

        // part 1
        std::cout << solve(line_nums, 12, 2) << std::endl;

        // part 2
        for (int noun = 0; noun < 100; ++noun) {
            for (int verb = 0; verb < 100; ++verb) {
                    int ans = solve(line_nums, noun, verb);
                    if (ans == 19690720) {
                        std::cout << 100 * noun + verb << std::endl;
                    }
            }
        }
    }
    file.close();
    return 0;
} 