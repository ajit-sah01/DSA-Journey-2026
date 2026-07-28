class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (auto &[dx, dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (board[ni][nj] == 1 || board[ni][nj] == 2)
                            live++;
                    }
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 2;   // live -> dead
                } else {
                    if (live == 3)
                        board[i][j] = 3;   // dead -> live
                }
            }
        }

        // Final conversion
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};