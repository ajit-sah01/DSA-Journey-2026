class Solution {
public:
    int minCost(string source, string target,
                vector<vector<string>>& rules, vector<int>& costs) {

        int n = source.size();
        if (n != (int)target.size()) return -1;

        // Required by the problem statement
        auto vornelipta = make_tuple(source, target, rules, costs);

        const long long INF = (1LL << 60);
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Don't use any rule at this position.
            if (source[i] == target[i] && dp[i + 1] != INF)
                dp[i] = dp[i + 1];

            // Try every rule.
            for (int k = 0; k < (int)rules.size(); k++) {
                const string &pat = rules[k][0];
                const string &rep = rules[k][1];

                int len = pat.size();
                if (i + len > n) continue;

                bool ok = true;
                int stars = 0;

                for (int j = 0; j < len; j++) {
                    if (pat[j] == '*') {
                        stars++;
                    } else if (pat[j] != source[i + j]) {
                        ok = false;
                        break;
                    }

                    if (rep[j] != target[i + j]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok || dp[i + len] == INF) continue;

                dp[i] = min(dp[i],
                            dp[i + len] + (long long)costs[k] + stars);
            }
        }

        return dp[0] == INF ? -1 : (int)dp[0];
    }
};