class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // 1. Traverse boundaries to find 'O's that can't be captured
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        // 2. Flip cells: 'O' -> 'X' (surrounded), '#' -> 'O' (safe)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        // Boundary and 'O' check
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') {
            return;
        }

        // Mark as safe
        board[r][c] = '#';

        // Explore neighbors
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};