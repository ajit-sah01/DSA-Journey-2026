class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        // Iterate over the smaller dimension
        if (m > n) {
            vector<vector<int>> trans(n, vector<int>(m));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    trans[j][i] = matrix[i][j];
            return maxSumSubmatrix(trans, k);
        }

        int ans = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);

            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++)
                    rowSum[i] += matrix[i][right];

                set<int> prefix;
                prefix.insert(0);

                int curSum = 0;

                for (int x : rowSum) {
                    curSum += x;

                    auto it = prefix.lower_bound(curSum - k);
                    if (it != prefix.end())
                        ans = max(ans, curSum - *it);

                    prefix.insert(curSum);
                }
            }
        }

        return ans;
    }
};