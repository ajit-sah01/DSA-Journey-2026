class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001 + 1, 0);

        for (auto &trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            diff[from] += passengers;
            diff[to] -= passengers;
        }

        int current = 0;

        for (int i = 0; i <= 1000; i++) {
            current += diff[i];

            if (current > capacity)
                return false;
        }

        return true;
    }
};