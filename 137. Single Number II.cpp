#include <vector>

using namespace std;

// This block ensures the fastest possible I/O in C++
static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 'ones' stores bits that have appeared 1 time (mod 3)
        // 'twos' stores bits that have appeared 2 times (mod 3)
        int ones = 0, twos = 0;

        for (const int& num : nums) {
            // Update 'ones' with the new bits, but only if they are not in 'twos'
            ones = (ones ^ num) & ~twos;

            // Update 'twos' with the new bits, but only if they are not in the new 'ones'
            twos = (twos ^ num) & ~ones;
        }

        // After the loop, the bits that appeared exactly once (1 mod 3) are in 'ones'
        return ones;
    }
};