//
// Created by hui on 19-5-21.
//

#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H

#include <vector>

class BinarySearch {
public:
  // 查找指定大小的值（无重复）
  static int binary_search_unique(std::vector<int> v, int target);

  // 求一个数的平方根（精确到小数点后6位）
  static double sqrt(double n);
  // 牛顿迭代法
  static double sqrt_newton(double n);

  // 查找第一个值等于定值的元素
  static int bin_search_first_eq(std::vector<int> v, int target);

  // 查找最后一个值等于定值的元素
  static int bin_search_last_eq(std::vector<int> v, int target);

  // 查找第一个大于等于定值的元素
  static int bin_search_first_ge(std::vector<int> v, int target);

  // 查找最后一个小于等于定值的元素
  static int bin_search_last_le(std::vector<int> v, int target);

  // 循环数组上的二分查找（无重复）
  static int bin_search_unique_cycle(std::vector<int> v, int target);
};

#endif // BINARYSEARCH_BINARYSEARCH_H
