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
  EXPECT_LE(std::abs(BinarySearch::sqrt_newton(1024) - std::sqrt(1024)),
            0.000001);
}

TEST(bin_search_first_eq, equal) {
  std::vector<int> v = {1, 3, 5, 5, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_first_eq(v, 5), 2);
  EXPECT_EQ(BinarySearch::bin_search_first_eq(v, 4), -1);
  EXPECT_EQ(BinarySearch::bin_search_first_eq(v, 1), 0);
  EXPECT_EQ(BinarySearch::bin_search_first_eq(v, 9), 5);

  std::vector<int> v2 = {-1, 3, 3, 5, 5, 7, 7, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_first_eq(v2, 7), 5);
}

TEST(bin_search_last_eq, equal) {
  std::vector<int> v = {1, 3, 5, 5, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_last_eq(v, 5), 3);
  EXPECT_EQ(BinarySearch::bin_search_last_eq(v, 4), -1);
  EXPECT_EQ(BinarySearch::bin_search_last_eq(v, 1), 0);
  EXPECT_EQ(BinarySearch::bin_search_last_eq(v, 9), 5);

  std::vector<int> v2 = {-1, 3, 3, 5, 5, 7, 7, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_last_eq(v2, 7), 7);
}

TEST(bin_search_first_ge, equal) {
  std::vector<int> v = {1, 3, 5, 5, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_first_ge(v, 5), 2);
  EXPECT_EQ(BinarySearch::bin_search_first_ge(v, 10), -1);
  EXPECT_EQ(BinarySearch::bin_search_first_ge(v, -10), 0);
  EXPECT_EQ(BinarySearch::bin_search_first_ge(v, 9), 5);

  std::vector<int> v2 = {-1, 3, 3, 5, 5, 7, 7, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_first_ge(v2, 7), 5);
}

TEST(bin_search_last_le, equal) {
  std::vector<int> v = {1, 3, 5, 5, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_last_le(v, 5), 3);
  EXPECT_EQ(BinarySearch::bin_search_last_le(v, 4), 1);
  EXPECT_EQ(BinarySearch::bin_search_last_le(v, 1), 0);
  EXPECT_EQ(BinarySearch::bin_search_last_le(v, 9), 5);

  std::vector<int> v2 = {-1, 3, 3, 5, 5, 7, 7, 7, 9};
  EXPECT_EQ(BinarySearch::bin_search_last_le(v2, 7), 7);
}