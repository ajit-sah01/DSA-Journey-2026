class Solution {
    unordered_map<int, int> mp;
    int limit;

public:
    Solution(int n, vector<int>& blacklist) {

        limit = n - blacklist.size();

        unordered_set<int> black;

        for (int x : blacklist)
            black.insert(x);

        int last = n - 1;

        for (int b : blacklist) {

            if (b >= limit)
                continue;

            while (black.count(last))
                last--;

            mp[b] = last;
            last--;
        }
    }

    int pick() {

        int x = rand() % limit;

        if (mp.count(x))
            return mp[x];

        return x;
    }
};