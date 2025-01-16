#pragma once
#include <_time.h>

#include <chrono>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
namespace common_util {

class Logger final {
  enum class Severity {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
  };

  enum class OutputMode {
    FILE,
    CONSOLE,
    UBIQUITOUS,
  };

  // do not use std::endl it flushes the whole buffer
  static constexpr char endl{'\n'};

  inline std::string get_string(const Severity severity) {
    std::string result{"NONE"};
    const static std::unordered_map<Severity, std::string> severity_string_map{{Severity::DEBUG, "DEBUG"},
                                                                               {Severity::INFO, "INFO"},
                                                                               {Severity::WARNING, "WARNING"},
                                                                               {Severity::ERROR, "ERROR"}};
    if (severity_string_map.count(severity))
      result = severity_string_map.at(severity);
    return result;
  }

private:
  // default time stamp formate for log
  std::function<std::string()> get_timestamp = []() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    auto in_milisecond = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm tm = *std::localtime(&now_time);
    std::ostringstream string_stream;
    string_stream << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    string_stream << '.' << std::setw(3) << std::setfill('0') << in_milisecond.count();
    return string_stream.str();
  };

  std::function<std::string()> get_this_thread_id = []() {
    std::ostringstream string_stream;
    string_stream << std::dec << std::this_thread::get_id();
    return string_stream.str();
  };
};
} // namespace common_util