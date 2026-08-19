// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int, int> freq;

//         for (int num : arr) {
//             freq[num]++;
//         }

//         int ans = -1;

//         for (auto &p : freq) {
//             if (p.first == p.second) {
//                 ans = max(ans, p.first);
//             }
//         }

//         return ans;
//     }
// };



// //// 2nd

// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int, int> freq;

//         for (int num : arr)
//             ++freq[num];

//         int ans = -1;

//         for (const auto& [num, count] : freq)
//             if (num == count)
//                 ans = max(ans, num);

//         return ans;
//     }
// };


///// 3rd

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};

        for (int num : arr)
            ++freq[num];

        for (int i = 500; i >= 1; --i) {
            if (freq[i] == i)
                return i;
        }

        return -1;
    }
};