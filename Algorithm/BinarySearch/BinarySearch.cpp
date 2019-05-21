//
// Created by hui on 19-5-21.
//

#include "BinarySearch.h"
#include <gtest/gtest.h>

int BinarySearch::binary_search_unique(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle = low + ((high - low) >> 1);

  while (low < high) {
    if (target < v[middle]) {
      high = middle;
    } else if (target > v[middle]) {
      low = middle;
    } else {
      return middle;
    }
  }
  return -1;
}



TEST(binary_search_unique, equal) {
  std::vector<int> v = {1, 3, 5, 7, 9};
  EXPECT_EQ(BinarySearch::binary_search_unique(v, 5), 2);
}

TEST(binary_search_unique, not_exist) {
  std::vector<int> v = {1, 3, 5, 7, 9};
  EXPECT_EQ(BinarySearch::binary_search_unique(v, 4), -1);
}
