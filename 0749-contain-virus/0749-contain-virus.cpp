class Solution {
public:
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int containVirus(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        while (true) {
            vector<vector<int>> vis(m, vector<int>(n, 0));

            vector<vector<pair<int,int>>> regions;
            vector<set<pair<int,int>>> frontiers;
            vector<int> walls;

            // Discover every infected region
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != 1 || vis[i][j]) continue;

                    vector<pair<int,int>> region;
                    set<pair<int,int>> frontier;
                    int wall = 0;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    while (!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();

                        region.push_back({x,y});

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                                continue;

                            if (grid[nx][ny] == 1 && !vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.push({nx,ny});
                            } else if (grid[nx][ny] == 0) {
                                wall++;
                                frontier.insert({nx,ny});
                            }
                        }
                    }

                    regions.push_back(region);
                    frontiers.push_back(frontier);
                    walls.push_back(wall);
                }
            }

            if (regions.empty()) break;

            int idx = -1;
            int mx = 0;

            for (int i = 0; i < frontiers.size(); i++) {
                if ((int)frontiers[i].size() > mx) {
                    mx = frontiers[i].size();
                    idx = i;
                }
            }

            if (mx == 0) break;

            ans += walls[idx];

            // Quarantine chosen region
            for (auto &cell : regions[idx]) {
                grid[cell.first][cell.second] = -1;
            }

            // Spread all other regions
            for (int i = 0; i < regions.size(); i++) {
                if (i == idx) continue;

                for (auto &cell : frontiers[i]) {
                    grid[cell.first][cell.second] = 1;
                }
            }
        }

        return ans;
    }
};