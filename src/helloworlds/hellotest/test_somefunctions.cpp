#include "somefunctions.h"
#include "gtest/gtest.h"
#include <limits.h>

// See http://google.github.io/googletest/primer.html

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(8), 40320);
}

// See https://github.com/google/googletest/blob/main/googletest/samples/sample1_unittest.cc

// Tests negative input.
TEST(IsPrimeTest, Negative) {
  // This test belongs to the IsPrimeTest test case.

  EXPECT_FALSE(isPrime(-1));
  EXPECT_FALSE(isPrime(-2));
  EXPECT_FALSE(isPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_FALSE(isPrime(0));
  EXPECT_FALSE(isPrime(1));
  EXPECT_TRUE(isPrime(2));
  EXPECT_TRUE(isPrime(3));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
  EXPECT_FALSE(isPrime(4));
  EXPECT_TRUE(isPrime(5));
  EXPECT_FALSE(isPrime(6));
  EXPECT_TRUE(isPrime(23));
}