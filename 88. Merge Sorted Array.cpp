class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for end of valid nums1
        int j = n - 1;      // Pointer for end of nums2
        int k = m + n - 1;  // Pointer for end of full nums1 array

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If elements remain in nums2, copy them
        // Note: If elements remain in nums1, they are already in place
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Fast I/O Optimization
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();