class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = findFirst(nums, target);
        if (left == -1)
            return {-1, -1};

        int right = findLast(nums, target);
        return {left, right};
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
                    ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
            {
                if (nums[mid] == target)
                    ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
