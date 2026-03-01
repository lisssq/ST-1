// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(CheckPrimeTest, SmallNumbers) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_TRUE(checkPrime(7));
}

TEST(CheckPrimeTest, CompositeNumbers) {
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(21));
  EXPECT_FALSE(checkPrime(25));
}

TEST(CheckPrimeTest, PrimeNumbers) {
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(29));
  EXPECT_TRUE(checkPrime(31));
  EXPECT_TRUE(checkPrime(37));
}

TEST(CheckPrime, LargePrime) {
  EXPECT_TRUE(checkPrime(999983));
  EXPECT_FALSE(checkPrime(999984));
}

TEST(NPrimeTest, FirstPrimes) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
  EXPECT_EQ(nPrime(4), 7);
  EXPECT_EQ(nPrime(5), 11);
  EXPECT_EQ(nPrime(6), 13);
  EXPECT_EQ(nPrime(7), 17);
  EXPECT_EQ(nPrime(8), 19);
  EXPECT_EQ(nPrime(9), 23);
  EXPECT_EQ(nPrime(10), 29);
}

TEST(NPrimeTest, EdgeCases) {
  EXPECT_EQ(nPrime(0), 0);
  EXPECT_EQ(nPrime(20), 71);
  EXPECT_EQ(nPrime(30), 113);
}

TEST(NextPrimeTest, Basic) {
  EXPECT_EQ(nextPrime(1), 2);
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(4), 5);
  EXPECT_EQ(nextPrime(8), 11);
  EXPECT_EQ(nextPrime(9), 11);
  EXPECT_EQ(nextPrime(10), 11);
}

TEST(NextPrimeTest, LargerNumbers) {
  EXPECT_EQ(nextPrime(11), 13);
  EXPECT_EQ(nextPrime(12), 13);
  EXPECT_EQ(nextPrime(17), 19);
  EXPECT_EQ(nextPrime(18), 19);
  EXPECT_EQ(nextPrime(19), 23);
  EXPECT_EQ(nextPrime(20), 23);
}

TEST(NextPrimeTest, RoundNumbers) {
  EXPECT_EQ(nextPrime(90), 97);
  EXPECT_EQ(nextPrime(100), 101);
  EXPECT_EQ(nextPrime(120), 127);
  EXPECT_EQ(nextPrime(150), 151);
}

TEST(SumPrimeTest, SmallBounds) {
  EXPECT_EQ(sumPrime(2), 0);
  EXPECT_EQ(sumPrime(3), 2);
  EXPECT_EQ(sumPrime(4), 5);
  EXPECT_EQ(sumPrime(5), 5);
  EXPECT_EQ(sumPrime(6), 10);
  EXPECT_EQ(sumPrime(7), 10);
  EXPECT_EQ(sumPrime(8), 17);
  EXPECT_EQ(sumPrime(9), 17);
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(11), 17);
}

TEST(SumPrimeTest, KnownSums) {
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(20), 77);
  EXPECT_EQ(sumPrime(30), 129);
}

TEST(SumPrimeTest, LargeBound) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
