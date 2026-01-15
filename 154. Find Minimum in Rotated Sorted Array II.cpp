class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // The minimum is definitely in the right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // The minimum is in the left half (including mid)
                right = mid;
            } else {
                // nums[mid] == nums[right]
                // We are unsure, so we shrink the search space by 1
                right--;
            }
        }

        return nums[left];
    }
};