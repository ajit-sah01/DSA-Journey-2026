class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Fast I/O Optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = prices.size();
        if (n < 2) return 0;

        int max_profit = 0;
        int min_price = prices[0];

        // Using a pointer-like access or standard loop with localized variables
        for (int i = 1; i < n; ++i) {
            int current_price = prices[i];

            // Branchless-style optimization:
            // Most prices won't be a new minimum, so we check profit first
            if (current_price > min_price) {
                int profit = current_price - min_price;
                if (profit > max_profit) max_profit = profit;
            } else {
                min_price = current_price;
            }
        }

        return max_profit;
    }
};