class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0 , maxSum = INT_MIN , n = nums.size()-1;

        for(int i = 0; i<= n ; i++ ){
            currSum += nums[i];
            maxSum = max(maxSum,currSum);

            if(currSum < 0){
                currSum = 0;
            }
        }

        return maxSum;

    }
};