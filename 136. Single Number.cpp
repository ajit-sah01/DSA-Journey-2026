#include <vector>

using namespace std;

// Fast I/O optimization for that 0ms result
static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Iterate through all numbers and XOR them
        // Using a range-based loop for clean, modern C++
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};