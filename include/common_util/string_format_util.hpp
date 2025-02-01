#pragma once
#include <iomanip>
#include <sstream>
#include <string>

namespace common_util {
template <typename... Args> std::string string_format(Args... args) {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(4);
  (stream << ... << args);
  return stream.str();
}

} // namespace common_util