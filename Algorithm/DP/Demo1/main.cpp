#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 1e9 + 10;

const int number = 4, capacity = 8;
int w[number + 1] = {0, 2, 3, 4, 5};
int v[number + 1] = {0, 3, 4, 5, 6};
int V[number + 1][capacity + 1];

void show() {
    for (int i = 0; i <= number; ++i) {
        cout << i << ": ";
        for (int j = 0; j <= capacity; ++j) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
}

void findMax() {
    for (int i = 1; i <= number; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (j < w[i]) {
                V[i][j] = V[i - 1][j];
            } else {
                if (V[i - 1][j] > V[i - 1][j - w[i]] + v[i]) {
                    V[i][j] = V[i - 1][j];
                } else {
                    V[i][j] = V[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }
}

void findWhat(int x, int y) {
    if (x >= 0) {
        if (V[x][y] == V[x - 1][y]) {
            // 没装
            findWhat(x - 1, y);
        } else if (y - w[x] >= 0 && V[x][y] == V[x - 1][y - w[x]] + v[x]) {
            cout << x << endl;
            findWhat(x - 1, y - w[x]);
        }
    }
}

int main() {
    show();
    findMax();
    show();
    findWhat(number, capacity);
}
