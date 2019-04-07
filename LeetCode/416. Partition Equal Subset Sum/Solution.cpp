#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const int &num:nums) {
            sum += num;
        }
        if (0 != (sum % 2)) {
            return false;
        }
        int target = sum / 2;

        bool dp[201][10001] = {false};

        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]);
                }
            }
        }

        return dp[nums.size()][target];
    }
};