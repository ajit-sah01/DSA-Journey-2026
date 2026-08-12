class Solution {
public:
    int ans = 0;

    void solve(int row, int n,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        // All queens placed
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check column and diagonals
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            // Place queen
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            solve(row + 1, n, col, diag1, diag2);

            // Backtrack
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);

        // Two diagonals:
        // row - col ranges from -(n-1) to (n-1)
        // row + col ranges from 0 to 2(n-1)
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, col, diag1, diag2);

        return ans;
    }
};