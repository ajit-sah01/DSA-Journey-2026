class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Boyer-Moore Voting Algorithm
        int candidate = 0;
        int count = 0;

        // Find candidate
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;

            if (num == candidate)
                count++;
            else
                count--;
        }

        // Verify candidate (needed only if majority isn't guaranteed)
        count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                count++;
        }

        return (count > nums.size() / 2) ? candidate : -1;
    }
};