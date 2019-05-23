//
// Created by hui on 19-5-23.
//

#include "BinarySearch.h"

#include <cmath>
#include <gtest/gtest.h>

TEST(binary_search_unique, equal) {
  std::vector<int> v = {1, 3, 5, 7, 9};
  EXPECT_EQ(BinarySearch::binary_search_unique(v, 5), 2);
}

TEST(binary_search_unique, not_exist) {
  std::vector<int> v = {1, 3, 5, 7, 9};
  EXPECT_EQ(BinarySearch::binary_search_unique(v, 4), -1);
}

TEST(sqrt, equal) {
  EXPECT_EQ(BinarySearch::sqrt(0), 0);
  EXPECT_EQ(BinarySearch::sqrt(4), 2);
  EXPECT_LE(std::abs(BinarySearch::sqrt(5) - std::sqrt(5)), 0.000001);
  EXPECT_LE(std::abs(BinarySearch::sqrt(1024) - std::sqrt(1024)), 0.000001);
}

TEST(sqrt_newton, equal) {
  EXPECT_EQ(BinarySearch::sqrt_newton(0), 0);
  EXPECT_EQ(BinarySearch::sqrt_newton(4), 2);
  EXPECT_LE(std::abs(BinarySearch::sqrt_newton(5) - std::sqrt(5)), 0.000001);
  EXPECT_LE(std::abs(BinarySearch::sqrt_newton(1024) - std::sqrt(1024)), 0.000001);
}