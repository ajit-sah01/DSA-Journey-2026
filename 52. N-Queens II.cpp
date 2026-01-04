class Solution {
public:
    int count = 0;

    void dfs(int n, int cols, int diag1, int diag2) {
        // All queens placed
        if (cols == (1 << n) - 1) {
            count++;
            return;
        }

        // Available positions
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            int bit = available & -available; // pick lowest set bit
            available -= bit;

            dfs(
                n,
                cols | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1
            );
        }
    }

    int totalNQueens(int n) {
        dfs(n, 0, 0, 0);
        return count;
    }
};
