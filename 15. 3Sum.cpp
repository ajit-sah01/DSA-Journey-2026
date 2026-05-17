#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
------------------------------------------------------------
3SUM PROBLEM
------------------------------------------------------------

Given an integer array nums,
return all unique triplets such that:

nums[i] + nums[j] + nums[k] == 0

------------------------------------------------------------
APPROACH USED
------------------------------------------------------------

Optimal Two Pointer Approach

1. Sort the array
2. Fix one element
3. Use two pointers:
      - left  -> i + 1
      - right -> n - 1
4. Move pointers based on current sum

------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Sorting      : O(n log n)
Two Pointer  : O(n²)

Overall      : O(n²)

------------------------------------------------------------
SPACE COMPLEXITY
------------------------------------------------------------

O(1) (excluding answer vector)

------------------------------------------------------------
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();

        // Step 1 : Sort the array
        sort(nums.begin(), nums.end());

        // Final answer vector
        vector<vector<int>> ans;

        // Step 2 : Fix one element
        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            // Step 3 : Apply Two Pointer Technique
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                // If sum is smaller, move left pointer
                if (sum < 0)
                {
                    left++;
                }

                // If sum is larger, move right pointer
                else if (sum > 0)
                {
                    right--;
                }

                // Valid triplet found
                else
                {
                    ans.push_back(
                        {
                            nums[i],
                            nums[left],
                            nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values for left pointer
                    while (left < right &&
                           nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    // Skip duplicate values for right pointer
                    while (left < right &&
                           nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
