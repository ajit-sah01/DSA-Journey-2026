#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // unordered_set provides O(1) average time complexity for lookups
        unordered_set<int> seen;

        for (int num : nums)
        {
            // If num is already in the set, we found a duplicate
            if (seen.find(num) != seen.end())
            {
                return true;
            }
            // Otherwise, insert it and keep going
            seen.insert(num);
        }

        return false;
    }
};