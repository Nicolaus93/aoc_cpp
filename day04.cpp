#include <array>
#include <cmath>
#include <iostream>

bool isValid(int n) {
  std::array<int, 6> digits;
  bool repeated{false};
  for (int pow = 0; pow < 6; ++pow) {
    int div = (int)std::pow(10, pow);
    int m = n / div;
    digits[pow] = m % 10;
    if (pow > 0 && digits[pow] > digits[pow - 1]) {
      // not increasing
      return false;
    }
    if (pow > 0 && digits[pow] == digits[pow - 1]) {
      repeated = true;
    }
  }
  if (repeated) {
    return true;
  }
  return false;
}

bool isValidStill(int n) {
  std::array<int, 10> count{};  // initialize to 0
  int digit = n % 10;
  count[digit]++;
  for (int pow = 1; pow < 6; ++pow) {
    int div = (int)std::pow(10, pow);
    int left_digit = (n / div) % 10;
    if (pow > 0 && left_digit > digit) {
      // not increasing
      return false;
    }
    digit = left_digit;
    count[digit]++;
  }
  for (auto c : count) {
    if (c == 2) {
      return true;
    }
  }
  return false;
}

int main() {
  int min_n = 136818;
  int max_n = 685979;
  int part_1 = 0;
  int part_2 = 0;

  for (int n = min_n; n <= max_n; ++n) {
    if (isValid(n)) {
      part_1++;
    }
    if (isValidStill(n)) {
      part_2++;
    }
  }
  std::cout << "part1: " << part_1 << std::endl;
  std::cout << "part2: " << part_2 << std::endl;
  return 0;
}
