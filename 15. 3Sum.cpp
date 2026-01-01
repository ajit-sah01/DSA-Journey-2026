#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {

            // Skip duplicate anchors
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Early pruning
            if (nums[i] > 0)
                break;

            int l = i + 1, r = n - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0)
                {
                    res.push_back({nums[i], nums[l], nums[r]});

                    int leftVal = nums[l];
                    int rightVal = nums[r];

                    // Skip duplicates efficiently
                    while (l < r && nums[l] == leftVal)
                        ++l;
                    while (l < r && nums[r] == rightVal)
                        --r;
                }
                else if (sum < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }
        return res;
    }
};
