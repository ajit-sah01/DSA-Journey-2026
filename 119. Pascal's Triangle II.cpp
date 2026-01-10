#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Pre-size the vector to the required row size
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // Base case: the first element is always 1

        for (int i = 1; i <= rowIndex; i++) {
            // Update from right to left to avoid using updated values
            // from the same row iteration
            for (int j = i; j >= 1; j--) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};