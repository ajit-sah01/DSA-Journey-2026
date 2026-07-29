class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for (long long factor = 1; factor <= n; factor *= 10) {
            long long low = n % factor;
            long long cur = (n / factor) % 10;
            long long high = n / (factor * 10);

            if (cur == 0)
                ans += high * factor;
            else if (cur == 1)
                ans += high * factor + low + 1;
            else
                ans += (high + 1) * factor;
        }

        return (int)ans;
    }
};