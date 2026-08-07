#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
private:
    // Floor division for negative numbers
    long long getBucketId(long long num, long long width) {
        if (num >= 0) {
            return num / width;
        }

        return ((num + 1) / width) - 1;
    }

public:
    bool containsNearbyAlmostDuplicate(
        vector<int>& nums,
        int indexDiff,
        int valueDiff
    ) {
        if (indexDiff <= 0 || valueDiff < 0) {
            return false;
        }

        unordered_map<long long, long long> bucket;

        // Bucket size = valueDiff + 1
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {

            long long num = nums[i];
            long long id = getBucketId(num, width);

            // 1. Same bucket
            if (bucket.count(id)) {
                return true;
            }

            // 2. Left neighboring bucket
            if (bucket.count(id - 1) &&
                num - bucket[id - 1] <= valueDiff) {
                return true;
            }

            // 3. Right neighboring bucket
            if (bucket.count(id + 1) &&
                bucket[id + 1] - num <= valueDiff) {
                return true;
            }

            // Add current element
            bucket[id] = num;

            // Maintain sliding window of size indexDiff
            if (i >= indexDiff) {
                long long oldNum = nums[i - indexDiff];
                long long oldId = getBucketId(oldNum, width);

                bucket.erase(oldId);
            }
        }

        return false;
    }
};