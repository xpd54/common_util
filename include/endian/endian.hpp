#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace common_util {

/*
  Endianness refers to the order in which bytes are stored for multi-byte data types.
  - Big-endian: Most significant byte is stored first.
  - Little-endian: Least significant byte is stored first.

  Example:
    here 0x12 is MSB(most significant bit), Big endian considered more human readable
    int16_t value = 0x1234;

    Big-endian representation in memory:
    Address:   0    1
    Value:   0x12 0x34

    Little-endian representation in memory:
    Address:   0    1
    Value:   0x34 0x12
*/
class Endian {
public:
  /* Convert from big-endian to little-endian or vice versa
    Thread safe.
   */
  Endian() = delete;
  Endian(const Endian &) = delete;
  Endian(Endian &&) = delete;
  ~Endian() = delete;

  Endian &operator=(const Endian &) = delete;
  Endian &operator=(Endian &&) = delete;

  static bool isBigEndian();
  static bool isLittleEndian();

  /*------------------------Read------------------------------------*/

  // read big endian signed 16 bit integer value from buffer, returns count of read bytes.
  static size_t readBigEndian(const void *buffer, int16_t &value);

  // read big endian unsigned 16 bit integer from buffer, returns count of read bytes.
  static size_t readBigEndian(const void *buffer, uint16_t &value);

  static size_t readBigEndian(const void *buffer, int32_t &value);
  static size_t readBigEndian(const void *buffer, uint32_t &value);

  static size_t readBigEndian(const void *buffer, int64_t &value);
  static size_t readBigEndian(const void *buffer, uint64_t &value);

  // read little endian signed 16 bit from buffer, returns count for read bytes.
  static size_t readLittleEndian(const void *buffer, int16_t &value);

  // read little endian unsigned 16 bit from buffer, returns count for read bytes.
  static size_t readLittleEndian(const void *buffer, uint16_t &value);

  static size_t readLittleEndian(const void *buffer, int32_t &value);
  static size_t readLittleEndian(const void *buffer, uint32_t &value);

  static size_t readLittleEndian(const void *buffer, int64_t &value);
  static size_t readLittleEndian(const void *buffer, uint64_t &value);

  /*------------------------Write------------------------------------*/

  // write big endian signed 16 bit integer to buffer, returns count of writtten bytes.
  static size_t writeBigEndian(void *buffer, int16_t value);

  // write big endian unsigned 16 bit integer to buffer, returns count of writtten bytes.
  static size_t writeBigEndian(void *buffer, uint16_t value);

  static size_t writeBigEndian(void *buffer, int32_t value);
  static size_t writeBigEndian(void *buffer, uint32_t value);

  static size_t writeBigEndian(void *buffer, int64_t value);
  static size_t writeBigEndian(void *buffer, uint64_t value);

  // write little endian signed 16 bit integer to buffer, returns count of written bytes.
  static size_t writeLittleEndian(void *buffer, int16_t value);

  // write little endian unsigned 16 bit integer to buffer, returns count of written bytes.
  static size_t writeLittleEndian(void *buffer, uint16_t value);

  static size_t writeLittleEndian(void *buffer, int32_t value);
  static size_t writeLittleEndian(void *buffer, uint32_t value);

  static size_t writeLittleEndian(void *buffer, int64_t value);
  static size_t writeLittleEndian(void *buffer, uint64_t value);
};
} // namespace common_util

#include "endian.inl"