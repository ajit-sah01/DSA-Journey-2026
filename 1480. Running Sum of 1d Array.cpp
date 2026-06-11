class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> ans (n,1);
        // ans[0] = nums[0];

        // for(int i =1 ; i<n ; i++){
        //    ans[i] = ans[i-1] + nums[i];
        // }
        // return ans;

        //// more better 

        int n = nums.size();
        for(int i =1; i<n ; i++){
            nums[i] += nums[i-1];
        }
        return nums;
        
    }
};
