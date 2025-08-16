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

/*--------------------------------implementation---------------------------------*/

/*
x86 architecture is little-endian. And this lib suppose to run on x86.
I am putting true and false as default. Would need to return little/big endian
for other case.
*/
inline bool Endian::isBigEndian() { return false; };
inline bool Endian::isLittleEndian() { return true; };

inline size_t Endian::readBigEndian(const void *buffer, int16_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[0];
  }
  return 2;
}

inline size_t Endian::readBigEndian(const void *buffer, uint16_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[0];
  }
  return 2;
}

inline size_t Endian::readBigEndian(const void *buffer, int32_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[0];
  }
  return 4;
}

inline size_t Endian::readBigEndian(const void *buffer, uint32_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[0];
  }
  return 4;
}

inline size_t Endian::readBigEndian(const void *buffer, int64_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[7];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[7];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[0];
  }
  return 8;
}

inline size_t Endian::readBigEndian(const void *buffer, uint64_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[7];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[7];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[0];
  }
  return 8;
}

inline size_t Endian::readLittleEndian(const void *buffer, int16_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
  }

  return 2;
}

inline size_t Endian::readLittleEndian(const void *buffer, uint16_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
  }

  return 2;
}

inline size_t Endian::readLittleEndian(const void *buffer, int32_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
  }

  return 4;
}

inline size_t Endian::readLittleEndian(const void *buffer, uint32_t &value) {

  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
  }

  return 4;
}

inline size_t Endian::readLittleEndian(const void *buffer, int64_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[7];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[7];
  }

  return 8;
}

inline size_t Endian::readLittleEndian(const void *buffer, uint64_t &value) {
  if (isBigEndian()) {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[7];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[0];
  } else {
    ((uint8_t *)&value)[0] = ((const uint8_t *)buffer)[0];
    ((uint8_t *)&value)[1] = ((const uint8_t *)buffer)[1];
    ((uint8_t *)&value)[2] = ((const uint8_t *)buffer)[2];
    ((uint8_t *)&value)[3] = ((const uint8_t *)buffer)[3];
    ((uint8_t *)&value)[4] = ((const uint8_t *)buffer)[4];
    ((uint8_t *)&value)[5] = ((const uint8_t *)buffer)[5];
    ((uint8_t *)&value)[6] = ((const uint8_t *)buffer)[6];
    ((uint8_t *)&value)[7] = ((const uint8_t *)buffer)[7];
  }

  return 8;
}

inline size_t Endian::writeBigEndian(void *buffer, int16_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[0];
  }

  return 2;
}

inline size_t Endian::writeBigEndian(void *buffer, uint16_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[0];
  }

  return 2;
}

inline size_t Endian::writeBigEndian(void *buffer, int32_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[0];
  }

  return 4;
}

inline size_t Endian::writeBigEndian(void *buffer, uint32_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[0];
  }

  return 4;
}

inline size_t Endian::writeBigEndian(void *buffer, int64_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[7];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[7];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[0];
  }

  return 8;
}

inline size_t Endian::writeBigEndian(void *buffer, uint64_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[7];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[7];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[0];
  }

  return 8;
}

inline size_t Endian::writeLittleEndian(void *buffer, int16_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
  }
  return 2;
}

inline size_t Endian::writeLittleEndian(void *buffer, uint16_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
  }
  return 2;
}

inline size_t Endian::writeLittleEndian(void *buffer, int32_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
  }

  return 4;
}

inline size_t Endian::writeLittleEndian(void *buffer, uint32_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
  }

  return 4;
}

inline size_t Endian::writeLittleEndian(void *buffer, int64_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[7];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[7];
  }

  return 8;
}

inline size_t Endian::writeLittleEndian(void *buffer, uint64_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[7];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[0];
  } else {
    ((uint8_t *)buffer)[0] = ((const uint8_t *)&value)[0];
    ((uint8_t *)buffer)[1] = ((const uint8_t *)&value)[1];
    ((uint8_t *)buffer)[2] = ((const uint8_t *)&value)[2];
    ((uint8_t *)buffer)[3] = ((const uint8_t *)&value)[3];
    ((uint8_t *)buffer)[4] = ((const uint8_t *)&value)[4];
    ((uint8_t *)buffer)[5] = ((const uint8_t *)&value)[5];
    ((uint8_t *)buffer)[6] = ((const uint8_t *)&value)[6];
    ((uint8_t *)buffer)[7] = ((const uint8_t *)&value)[7];
  }

  return 8;
}

} // namespace common_util