#include <iostream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

std::vector<std::vector<std::size_t>> integers = {{0, 1}, {2, 3}, {4, 5}, {6, 7}};
std::vector<std::vector<std::string>> strings = {{"zero", "one"}, {"two", "three"}, {"four", "five"}};

template <typename T>
std::string to_string(T value) {
  if constexpr (std::is_same<T, std::string>::value) {
    return value;
  } else {
    return std::to_string(value);
  }
}

template <typename T>
std::string vector_to_string(std::vector<T> vec, std::string separator = "\n") {
  std::string result = "";
  for (const auto& item : vec) {
    result.append(to_string(item));

    if (item != vec.back()) {
      result.append(separator);
    }
  }

  return result;
}

template <typename T>
std::vector<T> flatten(const std::vector<std::vector<T>>& to_flatten) {
  std::vector<T> new_vec = {};
  for (const auto& items : to_flatten) {
    for (const auto& item : items) {
      new_vec.push_back(item);
    }
  }

  return new_vec;
}

int main() {
  std::cout << vector_to_string(flatten(integers)) << std::endl;
  std::cout << vector_to_string(flatten(strings)) << std::endl;
  return EXIT_SUCCESS;
}