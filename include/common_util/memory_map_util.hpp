#pragma once
#include <cerrno>
#include <cstddef>
#include <fcntl.h>
#include <filesystem>
#include <ios>
#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <system_error>
#include <unistd.h>

namespace common_util {

template <typename T> class RMemoryMapped final {
public:
  RMemoryMapped(const std::filesystem::path &path) : filePath(path) {
    // Open file in read only
    file = open(filePath.c_str(), O_RDONLY);
    if (file == -1) {
      throw std::system_error(errno, std::iostream_category(), "Can't open file to read :- ");
    }
    struct stat sb;

    // get size of the file
    if (fstat(file, &sb) == -1)
      throw std::system_error(errno, std::iostream_category(), "Can't get size of file");
    // file size in bytes
    _size = sb.st_size;

    /*
     * maps the file into virtual memory ref (The Linux Programming Interface 49.2 Creating a Mapping: mmap())
     */
    _begin = mmap(NULL, _size, PROT_READ, MAP_PRIVATE, file, 0);
    if (_begin == MAP_FAILED)
      throw std::system_error(errno, std::iostream_category(), "Can't map file");
    file_begin = static_cast<T *>(_begin);
  }
  T *begin() { return file_begin; }
  T *end() { return file_begin + _size / sizeof(T); }
  size_t size() { return _size / sizeof(T); }
  ~RMemoryMapped() {
    if (_begin) {
      munmap(_begin, _size);
    }
    if (file) {
      close(file);
    }
  }
  // delete copy assignment, move assignment, copy constructor, move constructor
  RMemoryMapped(const RMemoryMapped &&) = delete;
  RMemoryMapped &operator=(const RMemoryMapped &&) = delete;
  RMemoryMapped(const RMemoryMapped &) = delete;
  RMemoryMapped &operator=(const RMemoryMapped &) = delete;

private:
  std::filesystem::path filePath;
  int file = -1;
  std::size_t _size;
  void *_begin;
  T *file_begin;
};

template <typename T> class WMemoryMapped final {
public:
  WMemoryMapped(const std::filesystem::path &path, size_t size) : filePath(path), _size(size) {
    // Open file in read only
    file = open(filePath.c_str(), O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (file == -1) {
      throw std::system_error(errno, std::iostream_category(), "Can't open file to write");
    }

    if (ftruncate(file, _size) == -1) {
      throw std::system_error(errno, std::iostream_category(), "Can't truncate size of file to write");
    }

    _begin = mmap(nullptr, _size, PROT_WRITE, MAP_SHARED, file, 0);
    if (_begin == MAP_FAILED)
      throw std::system_error(errno, std::iostream_category(), "Can't memory map file to write");
    file_begin = static_cast<T *>(_begin);
  }

  T *begin() { return file_begin; }
  T *end() { return file_begin + _size / sizeof(T); }
  size_t size() { return _size / sizeof(T); }

  void flush() {
    if (msync(_begin, _size, MS_SYNC) == -1) {
      throw std::system_error(errno, std::iostream_category(), "Memory failed to flush in file");
    }
  }

  ~WMemoryMapped() {
    if (_begin) {
      munmap(_begin, _size);
    }
    if (file) {
      close(file);
    }
  }

  // delete copy assignment, move assignment, copy constructor, move constructor
  WMemoryMapped(const WMemoryMapped &) = delete;
  WMemoryMapped *operator=(const WMemoryMapped &) = delete;
  WMemoryMapped(const WMemoryMapped &&) = delete;
  WMemoryMapped &operator=(const WMemoryMapped &&) = delete;

private:
  std::filesystem::path filePath;
  int file = -1;
  std::size_t _size;
  void *_begin;
  T *file_begin;
};
} // namespace common_util