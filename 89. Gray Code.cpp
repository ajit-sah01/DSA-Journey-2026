#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // 1 << n is equivalent to 2^n
        const int size = 1 << n;

        // Pre-allocate the vector with the exact size needed
        // This avoids any internal capacity checks during the loop
        vector<int> result(size);

        // Using a raw pointer for the fastest possible access
        int* ptr = result.data();

        for (int i = 0; i < size; ++i) {
            // Direct memory assignment is faster than push_back
            ptr[i] = i ^ (i >> 1);
        }

        return result;
    }
};

/** * Elite Level Optimization:
 * Disabling synchronization with C-style streams and
 * untying cin/cout makes I/O operations nearly instantaneous.
 */
static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();