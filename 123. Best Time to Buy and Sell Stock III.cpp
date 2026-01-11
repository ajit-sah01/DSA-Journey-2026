class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Fast I/O Optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // buy1/buy2: effective cost (we want to minimize this, so initialize to infinity)
        // sell1/sell2: profit (we want to maximize this, so initialize to 0)
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;

        for (int p : prices) {
            // 1st Transaction
            // How much does the first stock "cost" us?
            buy1 = min(buy1, p);
            // If we sell now, what's our profit?
            sell1 = max(sell1, p - buy1);

            // 2nd Transaction
            // How much does the second stock "cost" us?
            // We use the profit from sell1 to offset the price.
            buy2 = min(buy2, p - sell1);
            // What is our final total profit?
            sell2 = max(sell2, p - buy2);
        }

        return sell2;
    }
};