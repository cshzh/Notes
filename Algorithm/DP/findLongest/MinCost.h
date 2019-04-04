//
// Created by hui on 19-4-4.
//

#ifndef FINDLONGEST_MINCOST_H
#define FINDLONGEST_MINCOST_H

#include <bits/stdc++.h>

using namespace std;

/**
 * 对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2分别为三种操作的代价，请设计一个高效算法，
 * 求出将A串变为B串所需要的最少代价。
 * 给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300，且三种代价值均小于等于100。
 */
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        int iValue = c0;
        int dValue = c1;
        int mValue = c2;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dValue * i;
        }
        for (int i = 1; i <= m; i++) {
            dp[0][i] = iValue * i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // modify cost
                    int modifyCost = dp[i - 1][j - 1] + mValue;
                    // insert cost
                    int insertCost = dp[i][j - 1] + iValue;
                    // delete cost
                    int deleteCost = dp[i - 1][j] + dValue;

                    dp[i][j] = min(modifyCost, min(insertCost, deleteCost));
                }
            }
        }

        return dp[n][m];
    }
};


#endif //FINDLONGEST_MINCOST_H
