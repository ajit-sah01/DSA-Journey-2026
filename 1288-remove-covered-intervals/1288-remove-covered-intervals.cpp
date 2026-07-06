// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {

//         sort(intervals.begin(), intervals.end(),
//             [](vector<int>& a, vector<int>& b){
//                 if(a[0] == b[0])
//                     return a[1] > b[1];   // larger end first
//                 return a[0] < b[0];       // smaller start first
//             });

//         int count = 0;
//         int maxEnd = -1;

//         for(auto &it : intervals){
//             if(it[1] <= maxEnd){
//                 // covered
//                 continue;
//             }

//             count++;
//             maxEnd = it[1];
//         }

//         return count;
//     }
// };


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });

        int ans = 0;
        int maxEnd = -1;

        for (const auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                ++ans;
                maxEnd = interval[1];
            }
        }

        return ans;
    }
};