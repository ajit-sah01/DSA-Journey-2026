class Solution {
public:
    int maxArea(vector<int>& height) {
    int n = height.size();
    int MaxWater = 0;

    // // // TLE ERROR Bcoz this O(n2) 
    // for(int i = 0 ; i < n  ; i++){
    //     for(int j = i+1 ; j<n ; j++){
    //         int w = j-i;
    //         int ht = min(height[j], height[i]);
    //         int currWater = w * ht;

    //         MaxWater = max(MaxWater, currWater);
    //     }
    // }
    // return MaxWater;
    


    
     ///// left = st and right = end;
     // Two Pointer Approach Time O(n) Space O(1)
     int st = 0 , end = n-1, ans = INT_MIN;
     while(st<end){
        int w = end - st;
        int ht = min(height[st], height[end]);
        int currWater = w*ht;
        ans = max(ans ,currWater );
        height[st] < height[end] ? st++ : end--;
     }
     return ans;
    }
};

