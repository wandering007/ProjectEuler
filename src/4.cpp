#include <iostream>
#include <string>

bool is_palindrome(int n) {
  std::string n_str = std::to_string(n);
  int len = n_str.size();
  for (int i = 0; i <= (len - 1) / 2; ++i) {
    if (n_str[i] != n_str[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=4"
            << "\n\nLargest palindrome product" << std::endl;
  std::cout << "====================================" << std::endl;
  int larger_digit = 100, smaller_digit = 100;
  int largest_palindrome = 0;
  for (int i = 999; i >= smaller_digit; --i) {
    for (int j = i; j >= smaller_digit; --j) {
      int product = i * j;
      if (is_palindrome(product) and product > largest_palindrome) {
        largest_palindrome = product;
        larger_digit = i;
        smaller_digit = j;
      }
    }
  }
  std::cout << "The largest palindrome made from the product of two 3-digit "
               "numbers: "
            << largest_palindrome << std::endl;
  return 0;
}