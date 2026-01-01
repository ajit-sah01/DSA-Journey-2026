#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(const vector<int> &nums, int target)
    {
        unordered_map<int, int> index;
        index.reserve(nums.size());  // Avoid rehashing
        index.max_load_factor(0.7f); // Reduce collision probability

        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            const int complement = target - nums[i];

            auto it = index.find(complement);
            if (it != index.end())
            {
                return {it->second, i};
            }

            index.emplace(nums[i], i); // Faster than operator[]
        }

        return {};
    }
};
