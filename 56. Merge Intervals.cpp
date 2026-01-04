class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        int idx = 0; // index of last merged interval

        for (int i = 1; i < intervals.size(); i++) {
            // Overlap condition
            if (intervals[i][0] <= intervals[idx][1]) {
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            } else {
                idx++;
                intervals[idx] = intervals[i];
            }
        }

        intervals.resize(idx + 1);
        return intervals;
    }
};
