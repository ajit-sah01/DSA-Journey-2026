class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        // Using vectors for boundaries as you did, but we'll fill them without a stack
        vector<int> left(n);
        vector<int> right(n);

        // Calculate left boundaries: first index to the left with height < heights[i]
        left[0] = -1;
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            // "Jump" back using previously computed boundaries
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }

        // Calculate right boundaries: first index to the right with height < heights[i]
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            // "Jump" forward using previously computed boundaries
            while (p < n && heights[p] >= heights[i]) {
                p = right[p];
            }
            right[i] = p;
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            // Area = height * (right_boundary - left_boundary - 1)
            max_area = max(max_area, heights[i] * (right[i] - left[i] - 1));
        }

        return max_area;
    }
};

// Fast I/O optimization for LeetCode
static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();