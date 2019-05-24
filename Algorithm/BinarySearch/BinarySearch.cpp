//
// Created by hui on 19-5-21.
//

#include "BinarySearch.h"
#include <cmath>

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
      if (0 == middle || v[middle] != v[middle - 1]) {
        return middle;
      } else {
        high = middle - 1;
      }
    }
  }

  return -1;
}
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
      if ((v.size() - 1) == middle || v[middle] != v[middle + 1]) {
        return middle;
      } else {
        low = middle + 1;
      }
    }
  }

  return -1;
}
int BinarySearch::bin_search_first_ge(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target > v[middle]) {
      low = middle + 1;
    } else {
      if (0 == middle || v[middle - 1] < target) {
        return middle;
      } else {
        high = middle - 1;
      }
    }
  }

  return -1;
}
int BinarySearch::bin_search_last_le(std::vector<int> v, int target) {
  int low = 0;
  int high = v.size() - 1;
  int middle;

  while (low <= high) {
    middle = low + ((high - low) >> 1);

    if (target < v[middle]) {
      high = middle - 1;
    } else {
      if ((v.size() - 1) == middle || v[middle + 1] > target) {
        return middle;
      } else {
        low = middle + 1;
      }
    }
  }

  return -1;
}

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
