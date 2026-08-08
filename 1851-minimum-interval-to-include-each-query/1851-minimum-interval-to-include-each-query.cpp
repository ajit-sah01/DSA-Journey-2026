class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        // Sort intervals by left endpoint
        sort(intervals.begin(), intervals.end());

        // Store {query, original_index}
        vector<pair<int, int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        // Sort queries
        sort(qs.begin(), qs.end());

        // {length, right}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for (auto [query, index] : qs) {

            // Add all intervals that have started
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];

                int length = right - left + 1;

                pq.push({length, right});

                i++;
            }

            // Remove intervals that have already ended
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};