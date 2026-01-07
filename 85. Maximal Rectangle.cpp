class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();

        // Use raw arrays or vectors with pre-allocated memory for speed
        // h: height, l: left boundary, r: right boundary
        vector<int> h(n, 0), l(n, 0), r(n, n);
        int max_area = 0;

        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            const char* row_ptr = matrix[i].data();

            // 1. Compute height and left boundary in one linear pass
            for (int j = 0; j < n; ++j) {
                if (row_ptr[j] == '1') {
                    h[j]++;
                    l[j] = max(l[j], cur_left);
                } else {
                    h[j] = 0;
                    l[j] = 0;
                    cur_left = j + 1;
                }
            }

            // 2. Compute right boundary and calculate area in second linear pass
            for (int j = n - 1; j >= 0; --j) {
                if (row_ptr[j] == '1') {
                    r[j] = min(r[j], cur_right);
                    // Inline area calculation to maximize register usage
                    int area = h[j] * (r[j] - l[j]);
                    if (area > max_area) max_area = area;
                } else {
                    r[j] = n;
                    cur_right = j;
                }
            }
        }
        return max_area;
    }
};

// Advanced Fast I/O and pre-allocation trick
static const auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();