class Solution {
public:
    int maxProduct(int n) {
        int mx1 = -1, mx2 = -1;
        while (n > 0) {
            int d = n % 10;

            if (d >= mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if (d > mx2) {
                mx2 = d;
            }

            n /= 10;
        }

        return mx1 * mx2;
    }
};