class Solution {
public:
    string smallestGoodBase(string n) {

        unsigned long long num = stoull(n);

        int maxLen = log2(num);

        for (int m = maxLen + 1; m >= 2; m--) {

            unsigned long long k = pow(num, 1.0 / (m - 1));

            unsigned long long sum = 1;
            unsigned long long cur = 1;

            for (int i = 1; i < m; i++) {
                cur *= k;
                sum += cur;

                if (sum > num)
                    break;
            }

            if (sum == num)
                return to_string(k);
        }

        return to_string(num - 1);
    }
};