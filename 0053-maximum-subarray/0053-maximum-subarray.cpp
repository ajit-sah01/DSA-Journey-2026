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
        int currSum = 0, maxSum = INT_MIN;
           for(int i = 0; i < A.size(); i++) {
   	       currSum += A[i]; // Current subarray ka sum
      	maxSum = max(currSum, maxSum); // Maximum update
   	    if(currSum < 0) { // Agar loss ho raha hai
   		currSum = 0; // Naya subarray start karo
     	}
         }
       return maxSum;


     
    }
};