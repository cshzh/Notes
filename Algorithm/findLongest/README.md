# 最长公共子串

```c++
 // 最长公共子串
    int findLongest(string A, int n, string B, int m) {
        int ans = 0;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
```



# 最长公共子序列

```c++
// 最长公共子序列
int findLCS(string A, int n, string B, int m) {
        int ans = 0;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                    ans = std::max(ans, dp[i][j]);
                } else {
                    if (i > 0 && j > 0) {
                        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                    } else if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else if (j == 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return ans;
    }
```

