class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //   // O(n2) Time Complexity ..
    //   int n = nums.size();
    //   for(int i = 0 ; i<n;i++){
    //     for(int j = i+1 ; j<n;j++){

    //         if(nums[i] + nums[j] == target){
    //             return {i,j}; // if found ans return 
    //         };
    //     };
    //   };
    //   return {-1,-1}; // not find tha ans


    //  //   // O(n log n ) Time Complexity .. but not work proper !
    //     sort(nums.begin(), nums.end());
    //     int st = 0, end = nums.size() - 1;
    //     while (st < end)
    //     {
    //         if (nums[st] + nums[end] == target)
    //         {
    //             return {st, end};
    //         }
    //         else if (nums[st] + nums[end] > target)
    //         {
    //             end--;
    //         }
    //         else
    //         {
    //             st++;
    //         }
    //     }
    //     return {-1,-1};


        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int first = nums[i];
            int sec = target - first;

            if (m.find(sec) != m.end())
            {
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;



    };
};
