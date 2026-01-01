#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, long long target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i)
        {
            // Skip duplicate first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Early pruning
            long long min1 = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min1 > target)
                break;

            long long max1 = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (max1 < target)
                continue;

            for (int j = i + 1; j < n - 2; ++j)
            {
                // Skip duplicate second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long min2 = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > target)
                    break;

                long long max2 = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < target)
                    continue;

                int left = j + 1, right = n - 1;

                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
