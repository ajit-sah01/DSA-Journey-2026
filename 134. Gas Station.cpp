#include <vector>

using namespace std;

// This static block speeds up the C++ I/O operations
static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int current_tank = 0;
        int start_index = 0;

        // Using a pointer-based approach or raw array access
        // can sometimes be faster than vector indexing
        const int* g = gas.data();
        const int* c = cost.data();

        for (int i = 0; i < n; ++i) {
            int net = g[i] - c[i];
            total_surplus += net;
            current_tank += net;

            if (current_tank < 0) {
                start_index = i + 1;
                current_tank = 0;
            }
        }

        return (total_surplus < 0) ? -1 : start_index;
    }
};