class Solution {
public:
    void getPermuta(vector<int> &arr , int idx , vector<vector<int>> &ans){
        int n = arr.size();
        if(idx==n){
            ans.push_back({arr});
            return ;
        }

        for(int i = idx ; i<n ; i++){
            swap(arr[idx], arr[i]); //// idx place => ith element Choise
            getPermuta(arr,idx+1, ans);

            swap(arr[idx], arr[i]) ; // backTracing
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermuta(nums,0, ans);
        return ans;
    }
};
