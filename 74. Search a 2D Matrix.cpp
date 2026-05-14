#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//// Binaery Search in 2D Array
class Solution
{
public:
    bool SearchInRow(vector<vector<int>> &matrix, int target, int row) // O(log n)
    {
        int n = matrix[0].size();
        int st = 0, end = n - 1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid])
            {
                return true;
            }
            else if (target > matrix[row][mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target) // O(log m)
    {
        /// Bs on Tot Rows
        int m = matrix.size(), n = matrix[0].size();
        int starRow = 0, endRow = m - 1;
        while (starRow <= endRow)
        {
            int midRow = starRow + (endRow - starRow) / 2;

            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1])
            {
                // found The Row -> next Bs Serach in cols
                return SearchInRow(matrix, target, midRow);
            }
            else if (target > matrix[midRow][n - 1])
            {
                // down -> right
                starRow = midRow + 1;
            }
            else
            {
                // up -> left
                endRow = midRow - 1;
            }
        }

        return false;
    }
};