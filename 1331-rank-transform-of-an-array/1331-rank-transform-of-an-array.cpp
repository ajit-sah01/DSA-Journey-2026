class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int num : temp) {
            if (rank.find(num) == rank.end()) {
                rank[num] = r++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};