class Solution {
public:
    vector<vector<string>> results;
    vector<string> board;

    void solve(int row, int n, int cols, int diag1, int diag2) {
        // All queens placed successfully
        if (row == n) {
            results.push_back(board);
            return;
        }

        // Bitmask of all available positions in this row
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            // Pick the rightmost available position
            int bit = available & -available;
            available -= bit;

            int col = __builtin_ctz(bit);

            board[row][col] = 'Q';

            solve(
                row + 1,
                n,
                cols | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1
            );

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        solve(0, n, 0, 0, 0);
        return results;
    }
};
