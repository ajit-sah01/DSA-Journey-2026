class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            // If count is 0, we pick the current number as the new candidate
            if (count == 0) {
                candidate = num;
            }

            // If the current number is the same as the candidate, increment
            // Otherwise, decrement (the "vote" is canceled out)
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Since the problem guarantees a majority element exists, 
        // the remaining candidate is our answer.
        return candidate;
    }
};