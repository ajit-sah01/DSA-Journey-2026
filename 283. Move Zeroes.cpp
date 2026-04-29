#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 'j' is our slow pointer
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                // Swap the non-zero element at 'i' with the element at 'j'
                swap(nums[i], nums[j]);
                // Move the slow pointer forward
                j++;
            }
        }
    }
};