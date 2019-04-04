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

# 最长上升子序列

```c++
        // n*logn
		// 数组存于 A
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
```

# 最小编辑代价

```c++
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
```

