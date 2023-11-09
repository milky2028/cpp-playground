#include <string>
#include <chrono>

double mark_duration(std::string name, std::chrono::time_point<std::chrono::high_resolution_clock> start) {
  auto now = std::chrono::high_resolution_clock::now();
  auto duration_since = std::chrono::duration<double, std::milli>(now - start);
  return duration_since.count();
}