class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();

        // Pre-convert digits
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) a[i] = num1[i] - '0';
        for (int j = 0; j < m; j++) b[j] = num2[j] - '0';

        vector<int> res(n + m, 0);

        // Core multiplication
        for (int i = n - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = m - 1; j >= 0; j--) {
                int sum = a[i] * b[j] + res[i + j + 1] + carry;
                res[i + j + 1] = sum % 10;
                carry = sum / 10;
            }
            res[i] += carry;
        }

        // Build result string
        string ans;
        ans.reserve(n + m);
        int i = 0;
        while (i < res.size() && res[i] == 0) i++;
        for (; i < res.size(); i++)
            ans.push_back(res[i] + '0');

        return ans;
    }
};
