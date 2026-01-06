class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If current is 0, swap it to the 'low' boundary
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // If current is 1, it's already in the right middle area
                mid++;
            } else {
                // If current is 2, swap it to the 'high' boundary
                // Don't increment mid here because the swapped element
                // from 'high' hasn't been processed yet.
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};