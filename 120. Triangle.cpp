#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Start from the second-to-last row and move up
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                // The minimum path sum at this node is its value
                // plus the minimum of the two nodes directly below it.
                triangle[row][col] += min(triangle[row + 1][col],
                                        triangle[row + 1][col + 1]);
            }
        }

        // The top element now contains the minimum path sum for the whole triangle
        return triangle[0][0];
    }
};