//
// Created by hui on 19-4-4.
//

#ifndef FINDLONGEST_MIXTURE_H
#define FINDLONGEST_MIXTURE_H

#include <bits/stdc++.h>

using namespace std;

/**
 * 对于三个字符串A，B，C。我们称C由A和B交错组成当且仅当C包含且仅包含A，B中所有字符，且对应的顺序不改变。请编写一个高效算法，
 * 判断C串是否由A和B交错组成。
 * 给定三个字符串A,B和C，及他们的长度。请返回一个bool值，代表C是否由A和B交错组成。保证三个串的长度均小于等于100。
 */
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        if (v != n + m) {
            return false;
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1][0] && A[i - 1] == C[i - 1]) {
                dp[i][0] = true;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (dp[0][j - 1] && B[j - 1] == C[j - 1]) {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j] && C[i + j - 1] == A[i - 1])
                           || (dp[i][j - 1] && C[i + j - 1] == B[j - 1]);
            }
        }

        return dp[n][m];
    }
};


#endif //FINDLONGEST_MIXTURE_H
