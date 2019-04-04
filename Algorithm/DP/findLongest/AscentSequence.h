//
// Created by hui on 19-4-4.
//

#ifndef FINDLONGEST_ASCENTSEQUENCE_H
#define FINDLONGEST_ASCENTSEQUENCE_H

#include <bits/stdc++.h>

/**
 *  最长递增子序列
 */
class AscentSequence {

public:
    /**
     * O(nlogn)
     * @param A
     * @param n
     * @return
     */
    int findLongest(std::vector<int> A, int n) {
        if (A.empty() || n < 1) {
            return 0;
        }

        std::vector<int> vector;

        for (int i = 0; i < n; i++) {
            if (vector.empty() || A[i] >= vector.back()) {
                vector.push_back(A[i]);
            } else {

                // 从左到右查第一个大于当前数的数并替换之 （二分查找）
                int begin = 0;
                int end = vector.size();
                int middle = 0;

                while (begin < end) {
                    middle = begin + (end - begin) / 2;

                    if (vector[middle] <= A[i]) {
                        begin = middle + 1;
                    } else {
                        end = middle;
                    }
                }
                vector[begin] = A[i];
            }
        }

        return vector.size();
    }

    /**
     * O(n^2)
     * @param A
     * @param n
     * @return
     */
    int findLongest2(std::vector<int> A, int n) {
        if (A.empty() || n < 1) {
            return 0;
        }

        std::vector<int> vector;

        for (int i = 0; i < n; i++) {
            if (vector.empty() || A[i] >= vector.back()) {
                vector.push_back(A[i]);
            } else {
                // 从左到右查第一个大于当前数的数并替换之
                for (int j = 0; j < vector.size(); j++) {
                    if (vector[j] > A[i]) {
                        vector[j] = A[i];
                        break;
                    }
                }

            }
        }

        return vector.size();
    }

    /**
     * O(n^2)
     * @param A
     * @param n
     * @return
     */
    int findLongest1(std::vector<int> A, int n) {
        if (A.empty() || n < 1) {
            return 0;
        }

        int max = 1;
        std::vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[j] <= A[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (max < dp[i]) {
                        max = dp[i];
                    }
                }
            }
        }

        return max;
    }
};

#endif //FINDLONGEST_ASCENTSEQUENCE_H
