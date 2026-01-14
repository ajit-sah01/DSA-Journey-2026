#include <vector>
#include <unordered_map>
#include <numeric> // for std::gcd

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_pts = 1;

        for (int i = 0; i < n; ++i) {
            // map of {dy, dx} to count
            // Using a custom hash or a string key for the fraction
            unordered_map<long long, int> counts;
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Simplify the fraction using GCD
                int common = std::gcd(dx, dy);
                dx /= common;
                dy /= common;

                // Ensure a unique representation (e.g., dx is always positive)
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy); // Vertical line
                }

                // Pack dx and dy into a single 64-bit key for fast hashing
                // Constraints are 10^4, so they fit in 32-bit ints.
                long long key = ((long long)dx << 32) | (unsigned int)dy;

                counts[key]++;
                local_max = max(local_max, counts[key]);
            }
            // max_pts is local_max + 1 (the current point i itself)
            max_pts = max(max_pts, local_max + 1);
        }

        return max_pts;
    }
};