#pragma once
#include <ctime>
#include <iomanip>
#include <sstream>

/*
returns unix time.
std::cout << std::ctime(&tm);
Sun Oct  1 00:00:00 2017
*/
inline std::time_t convert_time_string(const std::string &timeString, const std::string format = "%Y-%m-%d %H:%M:%S") {
  std::tm tm = {};
  std::istringstream string_stream(timeString);
  // Parse the time string according to the given format
  string_stream >> std::get_time(&tm, format.c_str());
  if (string_stream.fail()) {
    throw std::runtime_error("Failed to parse time string");
  }
  // Convert std::tm to time_t
  return std::mktime(&tm);
}