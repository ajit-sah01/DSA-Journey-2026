class Solution{
public:
    int mirrorDistance(int n)
    {
        int original = n;
        int newN = 0;

        while (n > 0)
        {
            int rem = n % 10;
            newN = newN * 10 + rem;
            n = n / 10;
        }

        return abs(original - newN);
    }
};