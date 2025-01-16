#pragma once
#include <_time.h>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <mutex>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
namespace common_util {

class Logger final {
public:
  using type_timestamp_callback = std::function<std::string(void)>;
  using type_thread_id_callback = std::function<std::string(void)>;

public:
  Logger() {}

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
    const std::unordered_map<Severity, std::string> severity_string_map{{Severity::DEBUG, "DEBUG"},
                                                                        {Severity::INFO, "INFO"},
                                                                        {Severity::WARNING, "WARNING"},
                                                                        {Severity::ERROR, "ERROR"}};
    if (severity_string_map.count(severity))
      result = severity_string_map.at(severity);
    return result;
  }

  inline void set_timestamp_callback(type_timestamp_callback callback) {}
  inline void set_thread_id_callback(type_thread_id_callback callback) {}

private:
  type_timestamp_callback _timestamp_callback;
  type_thread_id_callback _thread_id_callback;

  std::mutex _logfile_mutex;
  std::mutex _partial_log_mutext;

  std::string _log_filename;
  std::ofstream _log_file_stream;

  Severity _log_severity = Severity::DEBUG;
  OutputMode _log_output_mode = OutputMode::UBIQUITOUS;

  bool _log_file_open = false;
  // default time stamp formate for log
  static std::string get_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    auto in_milisecond = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm tm = *std::localtime(&now_time);
    std::ostringstream string_stream;
    string_stream << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    string_stream << '.' << std::setw(3) << std::setfill('0') << in_milisecond.count();
    return string_stream.str();
  };

  static std::string get_this_thread_id() {
    std::ostringstream string_stream;
    string_stream << std::dec << std::this_thread::get_id();
    return string_stream.str();
  };

  static std::string get_default_log_filename() {
    std::string filename = get_timestamp();
    std::replace_if(
        filename.begin(), filename.end(), [](const char &c) { return std::isspace(c); }, '_');
    return filename + ".log";
  }

public:
  // delete copy constructor and assignment
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  // will have singleton instance
  static Logger &get_instance() {
    static Logger self;
    return self;
  }

  void init(const std::string &log_file_name = get_default_log_filename(),
            const Severity log_serverity = Severity::DEBUG, const OutputMode log_output_mode = OutputMode::UBIQUITOUS) {
    if (_log_file_open)
      return;
    _log_filename = log_file_name;
    _log_severity = log_serverity;
    _log_output_mode = log_output_mode;
  }
};
} // namespace common_util