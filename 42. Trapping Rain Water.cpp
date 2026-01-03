class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0;

        int maxh = h[0], maxidx = 0, sum = h[0], res = 0;

        for (int i = 1; i < n; i++) {
            if (h[i] >= maxh) {
                res += (i - maxidx) * maxh - sum;
                maxh = h[i];
                maxidx = i;
                sum = h[i];
            } else {
                sum += h[i];
            }
        }

        maxh = h[n - 1];
        maxidx = n - 1;
        sum = h[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (h[i] > maxh) {
                res += (maxidx - i) * maxh - sum;
                maxh = h[i];
                maxidx = i;
                sum = h[i];
            } else {
                sum += h[i];
            }
        }

        return res;
    }
};
