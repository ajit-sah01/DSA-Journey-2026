class Solution {
public:
    int findMin(vector<int>& nums) {
     
    //    int ans = INT_MAX;
    //    for(auto n : nums){
    //     ans = min(ans,n);
    //    } 
    //    return ans;


        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {

            int mid = left + (right - left) / 2;
            // Minimum is in right half
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Minimum is in left half including mid
            else if(nums[mid] < nums[right]) {
                right = mid;
            }
            // Duplicate case
            else {
                right--;
            }
        }
        return nums[left];





    }
};
