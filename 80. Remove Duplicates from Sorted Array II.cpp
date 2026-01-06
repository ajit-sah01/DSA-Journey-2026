// Fast I/O to hit 0ms
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        // 'j' is the write pointer.
        // We can always keep the first two elements.
        int j = 2;

        for (int i = 2; i < n; ++i) {
            // If the current element 'nums[i]' is different from
            // the element two places before the write pointer, it's safe to include.
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};