class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int k = primes.size();

        vector<long long> ugly(n);
        ugly[0] = 1;

        vector<int> idx(k, 0);
        vector<long long> next(k);

        for (int i = 0; i < k; i++)
            next[i] = primes[i];

        for (int i = 1; i < n; i++) {

            long long mn = *min_element(next.begin(), next.end());
            ugly[i] = mn;

            for (int j = 0; j < k; j++) {
                if (next[j] == mn) {
                    idx[j]++;
                    next[j] = 1LL * primes[j] * ugly[idx[j]];
                }
            }
        }

        return ugly[n - 1];
    }
};