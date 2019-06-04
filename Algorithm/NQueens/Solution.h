//
// Created by hui on 19-6-3.
//

#ifndef NQUEENS_SOLUTION_H
#define NQUEENS_SOLUTION_H

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveNQueens(vector<vector<string>> &rst, vector<string> &nQueen,
                      vector<int> &flag_col, vector<int> &flag_45, vector<int> &flag_135,
                      int i, int n) {
        if (i == n) {
            rst.push_back(nQueen);
            return;
        }
        for (int j = 0; j < n; j++) {


            if (flag_col[j]
                && flag_45[i + j]
                && flag_135[n - 1 + j - i]) {

                flag_col[j] = flag_45[i + j] = flag_135[n - 1 + j - i] = 0;
                nQueen[i][j] = 'Q';

                solveNQueens(rst, nQueen, flag_col, flag_45, flag_135, i + 1, n);

                flag_col[j] = flag_45[i + j] = flag_135[n - 1 + j - i] = 1;
                nQueen[i][j] = '.';
            }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rst;
        vector<string> nQueeen(n, string(n, '.'));
        vector<int> flag_col(n, 1);
        vector<int> flag_45(2 * n - 1, 1);
        vector<int> flag_135(2 * n - 1, 1);

        solveNQueens(rst, nQueeen, flag_col, flag_45, flag_135, 0, n);

        return rst;
    }
};


#endif //NQUEENS_SOLUTION_H
