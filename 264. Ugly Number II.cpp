class Solution
{
public:
    int nthUglyNumber(int n)
    {

        vector<int> ugly(n);

        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++)
        {

            int nextUgly = min({ugly[i2] * 2,
                                ugly[i3] * 3,
                                ugly[i5] * 5});

            ugly[i] = nextUgly;

            if (nextUgly == ugly[i2] * 2)
                i2++;
            if (nextUgly == ugly[i3] * 3)
                i3++;
            if (nextUgly == ugly[i5] * 5)
                i5++;
        }

        return ugly[n - 1];
    }
};