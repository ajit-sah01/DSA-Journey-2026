class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        set<pair<int, int>> corners;

        for (auto &r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            area += 1LL * (x2 - x1) * (y2 - y1);

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            vector<pair<int, int>> pts = {
                {x1, y1},
                {x1, y2},
                {x2, y1},
                {x2, y2}
            };

            for (auto &p : pts) {
                if (corners.count(p))
                    corners.erase(p);
                else
                    corners.insert(p);
            }
        }

        long long expectedArea = 1LL * (maxX - minX) * (maxY - minY);
        if (area != expectedArea) return false;

        if (corners.size() != 4) return false;

        return corners.count({minX, minY}) &&
               corners.count({minX, maxY}) &&
               corners.count({maxX, minY}) &&
               corners.count({maxX, maxY});
    }
};