class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();

    
    // // O(n) Linear Search 
    // for (int i = 0; i < n; i++)
    // {
    //     if (nums[i] == target)
    //     {
    //         return i; // target found
    //     }
    // }


    // bin search  O(log n)
    int st =0 , end = n-1;
    while(st<=end){ 
        int mid = st + (end - st) / 2 ;
        if(target == nums[mid]){
            return mid;
        }else if(nums[mid] < target){
            st = mid +1;
        }else{
            end = mid -1;
        }
    }

    return -1; // not found
    }
};
