class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // The minimum is in the right half
                left = mid + 1;
            } else {
                // The minimum is in the left half (including mid)
                right = mid;
            }
        }

        // When left == right, we've found the smallest element
        return nums[left];
    }
};