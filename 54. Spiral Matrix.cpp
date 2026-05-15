class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();

        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // top
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(mat[srow][i]);
            }

            // right
            for (int j = srow + 1; j <= erow; j++) {
                ans.push_back(mat[j][ecol]);
            }

            // bottom
            for (int k = ecol - 1; k >= scol; k--) {

                if (srow == erow)
                    break;

                ans.push_back(mat[erow][k]);
            }

            // left
            for (int l = erow - 1; l >= srow + 1; l--) {

                if (scol == ecol)
                    break;

                ans.push_back(mat[l][scol]);
            }

            srow++;
            scol++;

            erow--;
            ecol--;
        }

        return ans;
    }
};
