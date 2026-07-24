class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<int> values;
        vector<bool> seen(MAXX, false);

        // Keep only distinct values
        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                values.push_back(x);
            }
        }

        vector<bool> dp(MAXX, false), nxt(MAXX, false);
        dp[0] = true;

        for (int pick = 0; pick < 3; pick++) {
            fill(nxt.begin(), nxt.end(), false);

            for (int x = 0; x < MAXX; x++) {
                if (!dp[x]) continue;

                for (int v : values) {
                    nxt[x ^ v] = true;
                }
            }

            dp.swap(nxt);
        }

        int ans = 0;
        for (bool ok : dp)
            if (ok) ans++;

        return ans;
    }
};