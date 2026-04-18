#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        // prefix
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        // suffix
        int sufix = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            sufix *= nums[i + 1];
            ans[i] *= sufix;
        }
        return ans;
    }
};
