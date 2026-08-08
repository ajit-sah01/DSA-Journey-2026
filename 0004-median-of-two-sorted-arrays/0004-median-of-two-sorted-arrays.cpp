class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        // Number of elements that should be on the left side
        int half = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;

            // Boundary values
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Total length is odd
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Total length is even
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // nums1 partition is too far right
            if (left1 > right2) {
                right = i - 1;
            }
            // nums1 partition is too far left
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};