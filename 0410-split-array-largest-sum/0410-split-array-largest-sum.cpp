class Solution {
public:
    //// SAME LIKE BOOK ALLOCATION            
    bool Isvalid(vector<int> &nums  , int k , int mid){
        int curr = 1;
        int life = 0;
        int n = nums.size();
         if(k>n){
           return false;
        }
        for(int i = 0 ; i<n ; i++ ){
            if(nums[i]> mid){
                return false;
            }else if(life + nums[i] <= mid){
                life += nums[i];
            }else{
                curr++;
                life = nums[i];
            }
        }
        return curr <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        ///// More Improve In Space Using STL 
        // int Sum = 0 , Maxi = 0;
        // for(int val : nums){
        //     Sum += val;
        //     Maxi = max(Maxi , val);
        // }
        // int st =  Maxi, end = Sum, ans = -1;

        int st = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0) , ans =-1;

        while(st<=end){
            int mid = st + (end - st)/2;
            if(Isvalid(nums ,k , mid)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};