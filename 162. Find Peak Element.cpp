#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {

        //// O(n) approch
        // int n = nums.size();
        // int PeakMax = INT_MIN;
        // vector<int> ans;
        // for(int i = 0 ; i<n ; i++){
        //    PeakMax = max(PeakMax , nums[i]);
        // }
        // for(int i = 0 ; i<n ; i++){
        //     if(nums[i] == PeakMax){
        //     return i;
        //    }
        // }

        // // O(log n)
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l; // 🔥 yahi answer hai
    }
};