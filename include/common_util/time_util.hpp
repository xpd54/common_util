#pragma once
#include "string_format_util.hpp"
#include <_time.h>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

/*
returns unix time. (considers input timeString as utc time)
std::cout << std::ctime(&tm);
Sun Oct  1 00:00:00 2017
*/
inline std::time_t convert_time_string(const std::string &timeString, const std::string &format = "%Y-%m-%d %H:%M:%S") {
  std::tm tm = {};
  std::istringstream string_stream(timeString);
  // Parse the time string according to the given format
  string_stream >> std::get_time(&tm, format.c_str());
  if (string_stream.fail()) {
    throw std::runtime_error("Failed to parse time string");
  }
  // Convert std::tm to time_t, timegm consider that time is in utc
  return timegm(&tm);
}

/*
returns string formate from time_t
*/
inline std::string formate_time_utc(const std::time_t &time, const std::string &format = "%Y-%m-%d") {
  std::ostringstream stream;
  std::tm *utc = std::gmtime(&time);
  stream << std::put_time(utc, format.c_str());
  return stream.str();
}

inline std::string duration_to_string(const int64_t duration_sec) {
  const int64_t hours = duration_sec / 3600;
  const int64_t minutes = (duration_sec / 60) % 60;
  const int64_t seconds = duration_sec % 60;
  return common_util::string_format(hours, ':', minutes, ':', seconds);
}

inline std::time_t add_months(const std::time_t original_time, int months) {
  std::tm *tm = std::gmtime(&original_time);
  tm->tm_mon += months;
  std::time_t new_time = std::mktime(tm);
  return new_time;
}