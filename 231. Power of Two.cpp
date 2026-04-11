class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false; // Powers of 2 must be positive

        while (n % 2 == 0)
        {
            n /= 2; // Actually update n
        }

        return n == 1;
    }
};