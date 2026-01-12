#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Fast I/O optimization
static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        // Initialize everyone with 1 candy
        vector<int> candies(n, 1);

        // First Pass: Left to Right
        // If the current child has a higher rating than the left,
        // they get one more candy than the left child.
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Second Pass: Right to Left
        // If the current child has a higher rating than the right,
        // they must have more than the right child.
        // We use max() to ensure we don't break the Left-to-Right condition.
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum up all candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};