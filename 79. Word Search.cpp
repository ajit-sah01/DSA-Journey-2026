class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base Case: All characters found
        if (index == word.length()) return true;

        // Boundary and character mismatch check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions: Down, Up, Right, Left
        bool found = backtrack(board, word, i + 1, j, index + 1) ||
                     backtrack(board, word, i - 1, j, index + 1) ||
                     backtrack(board, word, i, j + 1, index + 1) ||
                     backtrack(board, word, i, j - 1, index + 1);

        // Restore the cell (Backtrack)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Pruning: Word cannot be longer than the total number of cells
        if (word.length() > m * n) return false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};