# 一文说尽“二分查找”

本文总结了二分查找算法及其变种。

## 查找指定大小的值（无重复）

```cpp
int BinarySearch::binary_search_unique(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {

    middle = low + ((high - low) >> 1);

    if (target < v[middle]) {
      high = middle - 1;
    } else if (target > v[middle]) {
      low = middle + 1;
    } else {
      return middle;
    }
  }

  return -1;
}
```

## 查找第一个值等于定值的元素（有重复）

```cpp
int BinarySearch::bin_search_first_eq(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target < v[middle]) {
      high = middle - 1;
    } else if (target > v[middle]) {
      low = middle + 1;
    } else {
      // 不直接返回，而是判断自己是否为所有相等元素中的第一个元素
      if (0 == middle || v[middle] != v[middle - 1]) {
        return middle;
      } else {
        high = middle - 1;
      }
    }
  }

  return -1;
}
```



## 查找最后一个值等于定值的元素

```cpp
int BinarySearch::bin_search_last_eq(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target < v[middle]) {
      high = middle - 1;
    } else if (target > v[middle]) {
      low = middle + 1;
    } else {
      // 不直接返回，而是判断自己是否为所有相等元素中的最后一个元素
      if ((v.size() - 1) == middle || v[middle] != v[middle + 1]) {
        return middle;
      } else {
        low = middle + 1;
      }
    }
  }

  return -1;
}
```

## 查找第一个大于等于定值的元素

```cpp
int BinarySearch::bin_search_first_ge(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target > v[middle]) {
      low = middle + 1;
    } else {
      // 判断自己是否为所有符合要求的元素中的第一个
      if (0 == middle || v[middle - 1] < target) {
        return middle;
      } else {
        high = middle - 1;
      }
    }
  }

  return -1;
}
```



## 查找最后一个小于等于定值的元素

```cpp
int BinarySearch::bin_search_last_le(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target < v[middle]) {
      high = middle - 1;
    } else {
      // 判断自己是否为所有符合要求的元素中的最后一个
      if ((v.size() - 1) == middle || v[middle + 1] > target) {
        return middle;
      } else {
        low = middle + 1;
      }
    }
  }

  return -1;
}
```



## 循环数组上的二分查找（无重复）

leetcode: [search-in-rotated-sorted-array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

```cpp
int BinarySearch::bin_search_unique_cycle(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (v[low] <= v[high]) {
      if (v[middle] > target) {
        high = middle - 1;
      } else if (v[middle] < target) {
        low = middle + 1;
      } else {
        return middle;
      }
    } else {
      if (v[low] <= v[middle]) {
        if (target > v[middle]) {
          low = middle + 1;
        } else if (target < v[middle]) {
          if (target > v[low]) {
            high = middle - 1;
          } else if (target < v[low]) {
            low = middle + 1;
          } else {
            return low;
          }
        } else {
          return middle;
        }
      } else {
        if (target > v[high]) {
          high = middle - 1;
        } else if (target < v[high]) {
          if (target > v[middle]) {
            low = middle + 1;
          } else if (target < v[middle]) {
            high = middle - 1;
          } else {
            return middle;
          }
        } else {
          return high;
        }
      }
    }
  }

  return -1;
}
```



## 循环数组上的查找最小元素（无重复）

leetcode: [find-minimum-in-rotated-sorted-array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)

```cpp
int BinarySearch::find_min_unique_cycle(std::vector<int> v) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (v[low] <= v[high]) {
      return v[low];
    } else {
      if (v[low] <= v[middle]) {
        low = middle + 1;
      } else {
        if (0 == middle || v[middle - 1] > v[middle]) {
          return v[middle];
        } else {
          high = middle - 1;
        }
      }
    }
  }

  return 0;
}
```

## 循环数组上的二分查找

leetcode: [search-in-rotated-sorted-array-ii](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

```cpp
int BinarySearch::bin_search_cycle(std::vector<int> v, int target) {
  // TODO
  return 0;
}
```



## 循环数组上的查找最小元素

leetcode: [find-minimum-in-rotated-sorted-array-ii](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

```cpp
int BinarySearch::find_min_cycle(std::vector<int> v) {
  // TODO
  return 0;
}
```



# 应用

## 求一个数的平方根

```cpp
double BinarySearch::sqrt(double n) {
  double epsilon = 0.000001;

  double low = 0.0;
  double high = n;
  double middle;

  while (low <= high) {
    middle = low + ((high - low) / 2.0);

    if (std::abs(middle * middle - n) < epsilon) {
      return middle;
    }

    if (middle * middle > n) {
      high = middle;
    } else {
      low = middle;
    }
  }
}
```

当然，这里使用“牛顿迭代法”更合适，下面也给出它的实现

```cpp
double BinarySearch::sqrt_newton(double n) {
  double epsilon = 0.000001;

  double x_0 = n / 2.0;
  double x = n / 2.0;

  while (true) {
    if (std::abs(x_0 * x_0 - n) < epsilon) {
      return x_0;
    }

    x = x_0 - ((x_0 * x_0 - n) / (2.0 * x_0));

    x_0 = x;
  }
}
```