#pragma once
#include <iostream>

namespace common_util {
class WriteChar {
public:
  explicit WriteChar(char ch) : _ch(ch) {}
  friend std::ostream &operator<<(std::ostream &stream, const WriteChar &writer) {
    return stream << '\'' << writer._ch << '\'';
  }

private:
  char _ch;
};

class WriteString {
public:
  template <size_t N> explicit WriteString(const char (&str)[N]) : _str(str), _size(N) {}
  friend std::ostream &operator<<(std::ostream &stream, const WriteString &writer) {
    stream << '"';
    stream.write(writer._str, writer._size);
    stream << '"';
    return stream;
  }

private:
  const char *_str;
  size_t _size;
};
} // namespace common_util