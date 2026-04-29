#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    // O(n2) Time Complexity ..
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] + nums[j] == target)
        {
          return {i, j}; // if found ans return
        };
      };
    };
    return {-1, -1}; // not find tha ans
  };
};
