class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> fact(n + 1, 1);

        // Precompute factorials
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            numbers.push_back(i);
        }

        // Convert k to 0-based index
        k--;

        string result;

        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];

            result += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
        }

        return result;
    }
};
