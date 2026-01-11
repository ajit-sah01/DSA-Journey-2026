class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Fast I/O to hit the 0ms mark
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_profit = 0;
        int n = prices.size();

        // Loop from the second day to the end
        for (int i = 1; i < n; ++i) {
            // If the price increased from yesterday, grab that profit
            // This is branch-heavy, but necessary logic
            if (prices[i] > prices[i - 1]) {
                max_profit += (prices[i] - prices[i - 1]);
            }
        }

        return max_profit;
    }
};