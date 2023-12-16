#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "arithmetic/arithmetic.h"

TEST_GROUP(Arithmetic){};

TEST(Arithmetic, AddNormalValue) { LONGS_EQUAL(30, add(10, 20)); }

TEST(Arithmetic, AddOverflowValue) {
  LONGS_EQUAL(0, add(0xFFFFFFFF, 1));
  LONGS_EQUAL(9, add(0xFFFFFFF5, 20));
}

TEST(Arithmetic, SaturatingAddNormalValue) {
  LONGS_EQUAL(30, saturating_add(10, 20));
  LONGS_EQUAL(0x100, saturating_add(128, 128));
  LONGS_EQUAL(0x10000, saturating_add(0xFFFF, 1));
}

TEST(Arithmetic, SaturatingAddOverflowValue) {
  LONGS_EQUAL(0xFFFFFFFF, saturating_add(0xFFFFFFFF, 1));
  LONGS_EQUAL(0xFFFFFFFF, saturating_add(0xFFFFFFF5, 20));
}
