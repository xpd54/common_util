#pragma once
#include <sstream>
#include <string>

namespace common_util {
template <typename... Args> std::string string_format(Args... args) {
  std::ostringstream stream;
  (stream << ... << args);
  return stream.str();
}

} // namespace common_util