#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(const string &s)
    {
        static int val[128] = {
            ['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50, ['C'] = 100, ['D'] = 500, ['M'] = 1000};

        int total = 0;
        int maxSeen = 0;

        for (int i = s.size() - 1; i >= 0; --i)
        {
            int curr = val[s[i]];
            if (curr < maxSeen)
                total -= curr;
            else
            {
                total += curr;
                maxSeen = curr;
            }
        }
        return total;
    }
};
