#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    int maximumGap(std::vector<int> &nums)
    {

        int n = nums.size();

        if (n < 2)
        {
            return 0;
        }

        auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());

        int minVal = *minIt;
        int maxVal = *maxIt;

        if (minVal == maxVal)
        {
            return 0;
        }

        // Ceiling division
        int bucketSize = std::max(
            1,
            (maxVal - minVal + n - 2) / (n - 1));

        int bucketCount =
            (maxVal - minVal) / bucketSize + 1;

        std::vector<int> bucketMin(bucketCount, INT_MAX);
        std::vector<int> bucketMax(bucketCount, INT_MIN);

        // Fill buckets
        for (int num : nums)
        {

            int idx = (num - minVal) / bucketSize;

            bucketMin[idx] =
                std::min(bucketMin[idx], num);

            bucketMax[idx] =
                std::max(bucketMax[idx], num);
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; ++i)
        {

            // Empty bucket
            if (bucketMin[i] == INT_MAX)
            {
                continue;
            }

            maxGap =
                std::max(maxGap,
                         bucketMin[i] - prevMax);

            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};