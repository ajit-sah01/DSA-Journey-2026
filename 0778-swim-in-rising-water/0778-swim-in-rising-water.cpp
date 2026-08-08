class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // {elevation, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int ans = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            // Water must be at least this high
            ans = max(ans, height);

            // Destination reached
            if (r == n - 1 && c == n - 1) {
                return ans;
            }

            // Explore 4 directions
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = true;

                    pq.push({
                        grid[nr][nc],
                        nr,
                        nc
                    });
                }
            }
        }

        return -1;
    }
};