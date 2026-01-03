class Solution {
public:
    struct Hash {
        size_t operator()(const array<int, 26>& a) const noexcept {
            size_t h = 0;
            for (int x : a) {
                h = h * 31 + x;
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, Hash> mp;
        mp.reserve(strs.size());

        for (const string& s : strs) {
            array<int, 26> freq{};
            for (char c : s) {
                freq[c - 'a']++;
            }
            mp[freq].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());

        for (auto& it : mp) {
            result.push_back(move(it.second));
        }

        return result;
    }
};
