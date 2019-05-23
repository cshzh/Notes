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
