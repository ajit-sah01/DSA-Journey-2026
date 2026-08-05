class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const long long MOD = 1e9 + 7;

        // {x, type, y1, y2}
        vector<array<int, 4>> events;

        for (auto &r : rectangles) {
            events.push_back({r[0], 1, r[1], r[3]});
            events.push_back({r[2], -1, r[1], r[3]});
        }

        sort(events.begin(), events.end());

        // {y1, y2}
        vector<pair<int, int>> active;

        long long area = 0;
        long long prevX = events[0][0];

        for (auto &e : events) {
            long long x = e[0];

            // Calculate total covered Y length
            long long coveredY = 0;

            if (!active.empty()) {
                vector<pair<int, int>> temp = active;
                sort(temp.begin(), temp.end());

                long long start = temp[0].first;
                long long end = temp[0].second;

                for (int i = 1; i < temp.size(); i++) {
                    if (temp[i].first > end) {
                        coveredY += end - start;
                        start = temp[i].first;
                        end = temp[i].second;
                    } else {
                        end = max(end, (long long)temp[i].second);
                    }
                }

                coveredY += end - start;
            }

            // Width * covered height
            area = (area + coveredY * (x - prevX)) % MOD;

            // Process current event
            int type = e[1];
            int y1 = e[2];
            int y2 = e[3];

            if (type == 1) {
                active.push_back({y1, y2});
            } else {
                for (int i = 0; i < active.size(); i++) {
                    if (active[i].first == y1 &&
                        active[i].second == y2) {

                        active.erase(active.begin() + i);
                        break;
                    }
                }
            }

            prevX = x;
        }

        return area;
    }
};