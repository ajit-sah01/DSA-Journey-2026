class Solution {
public:
    int maxSubArray(vector<int>& A) {

        // //// Kadane's Algorithm 
        // int currSum = 0 , maxSum = INT_MIN;
        // for(int i = 0; i<A.size(); i++){
        //     currSum += A[i];
        //     maxSum = max(maxSum, currSum);
        //     if(currSum < 0){
        //         currSum = 0;
        //     }
        // }
        // return maxSum;


        //// Kadane's Algorithm 
        int currSum = 0 , maxSum = INT_MIN;
        for(int i = 0 ; i<A.size(); i++){
            currSum += A[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};