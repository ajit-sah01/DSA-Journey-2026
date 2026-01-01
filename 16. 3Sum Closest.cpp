#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int best = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i)
        {

            // Skip duplicate anchors (safe optimization)
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Strong pruning using bounds
            int minSum = nums[i] + nums[i + 1] + nums[i + 2];
            if (minSum > target)
            {
                if (abs(minSum - target) < abs(best - target))
                    best = minSum;
                break; // further i will only increase sum
            }

            int maxSum = nums[i] + nums[n - 2] + nums[n - 1];
            if (maxSum < target)
            {
                if (abs(maxSum - target) < abs(best - target))
                    best = maxSum;
                continue;
            }

            int l = i + 1, r = n - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < abs(best - target))
                    best = sum;

                if (sum == target)
                    return sum;
                else if (sum < target)
                    ++l;
                else
                    --r;
            }
        }
        return best;
    }
};
