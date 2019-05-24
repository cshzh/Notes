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

TEST(bin_search_unique_cycle, not_find) {
  std::vector<int> v = {1, 3, 5, 7, 9};

  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, -1), -1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 4), -1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 12), -1);

  v.clear();

  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 5), -1);

  std::vector<int> v2 = {7, 9, 1, 3, 5};

  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, -1), -1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 4), -1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 12), -1);
}

TEST(bin_search_unique_cycle, find) {
  std::vector<int> v = {7, 9, 1, 3, 5};

  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 7), 0);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 9), 1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 1), 2);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 3), 3);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v, 5), 4);


  std::vector<int> v2 = {2, 4, 6, 8, 10 ,12, 14, 16};

  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 4), 1);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 8), 3);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 12), 5);
  EXPECT_EQ(BinarySearch::bin_search_unique_cycle(v2, 16), 7);
}

TEST(find_min_unique_cycle, find) {
  std::vector<int> v = {7, 9, 1, 3, 5};

  EXPECT_EQ(BinarySearch::find_min_unique_cycle(v), 1);

  std::vector<int> v2 = {2, 4, 6, 8, 10 ,12, 14, 16};

  EXPECT_EQ(BinarySearch::find_min_unique_cycle(v2), 2);

  std::vector<int> v3 = {4, 6, 8, 10 ,12, 14, 16, 2};

  EXPECT_EQ(BinarySearch::find_min_unique_cycle(v3), 2);

  std::vector<int> v4 = {12, 14, 16, 2, 4, 6, 8, 10};

  EXPECT_EQ(BinarySearch::find_min_unique_cycle(v4), 2);

  std::vector<int> v5 = {10, 12, 14, 16, 2, 4, 6, 8};

  EXPECT_EQ(BinarySearch::find_min_unique_cycle(v5), 2);
}