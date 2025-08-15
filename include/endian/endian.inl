namespace common_util {
class Endian;
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
    ((uint8_t *)buffer)[0] = (const uint8_t *)&value[1];
    ((uint8_t *)buffer)[1] = (const uint8_t *)&value[0];
  } else {
    ((uint8_t *)buffer)[0] = (const uint8_t *)&value[0];
    ((uint8_t *)buffer)[1] = (const uint8_t *)&value[1];
  }
  return 2;
}

inline size_t Endian::writeLittleEndian(void *buffer, uint16_t value) {
  if (isBigEndian()) {
    ((uint8_t *)buffer)[0] = (const uint8_t *)&value[1];
    ((uint8_t *)buffer)[1] = (const uint8_t *)&value[0];
  } else {
    ((uint8_t *)buffer)[0] = (const uint8_t *)&value[0];
    ((uint8_t *)buffer)[1] = (const uint8_t *)&value[1];
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
  if (IsBigEndian()) {
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
  if (IsBigEndian()) {
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