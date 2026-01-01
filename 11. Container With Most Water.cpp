#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int i = 0, j = h.size() - 1;
        int best = 0;

        while (i < j)
        {
            int left = h[i];
            int right = h[j];
            int area = (left < right ? left : right) * (j - i);
            if (area > best)
                best = area;

            // Skip all heights <= current limiting height
            if (left < right)
            {
                while (i < j && h[i] <= left)
                    ++i;
            }
            else
            {
                while (i < j && h[j] <= right)
                    --j;
            }
        }
        return best;
    }
};
