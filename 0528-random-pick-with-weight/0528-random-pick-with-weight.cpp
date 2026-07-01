class Solution {
    vector<int> prefix;

public:
    Solution(vector<int>& w) {

        int sum = 0;

        for (int x : w) {
            sum += x;
            prefix.push_back(sum);
        }
    }

    int pickIndex() {

        int total = prefix.back();

        int target = rand() % total + 1;

        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};