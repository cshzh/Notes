#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101
int D[MAX][MAX], maxSum[MAX][MAX];
int n;

int plan1();

void plan2();

int MaxSum(int i, int j) {
    if (i == n) {
        return D[i][j];
    }
    int x = MaxSum(i + 1, j);
    int y = MaxSum(i + 1, j + 1);

    return max(x, y) + D[i][j];
}

int main() {
    plan2();

}

/**
 * 动态规划
 */
void plan2() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> D[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        maxSum[n][i] = D[n][i];
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + D[i][j];
        }
    }

    cout << maxSum[1][1] << endl;
}

/**
 * 测试输入:
    5
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
 * 简单直接递归
 * @return
 */
int plan1() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> D[i][j];
        }
    }

    cout << MaxSum(1, 1) << endl;

    return 0;
}