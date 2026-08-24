class Solution {
public:
    //// Helper Function
    // int binSerach(vector<int>& arr, int tar, int st, int end){
    //     if(st>end){
    //         return -1;
    //     }
    //     int mid = st + (end-st)/2;
    //     // Found 
    //     if(arr[mid] == tar){
    //         return mid;
    //     }
    //     // left hafe
    //     else if(arr[mid] > tar){
    //         return binSerach(arr,tar, st, mid-1);
    //     }
    //     // right hafe
    //     else{
    //         return binSerach(arr,tar,mid+1, end);
    //     }
    // }

    // main Function
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




    // Call Hapler Function  using recursuion
    //    return binSerach(nums,target,0, n-1);


    // // bin search  O(log n)
    int st = 0 , end = n-1;
    while(st<=end){
        int mid = st+ (end-st)/2;
        if(nums[mid] == target){
            return mid;
        }else if(target > nums[mid]){
            st = mid+1;
        }else {
            end = mid-1;
        }
    }
    return -1;// not found
    }
};


