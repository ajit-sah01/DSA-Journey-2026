class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // Powers of four must be positive
        if (n <= 0)
            return false;

        // Keep dividing by 4 if there is no remainder
        while (n % 4 == 0)
        {
            n /= 4;
        }

        // If we reach 1, it's a power of four
        return n == 1;
    }
};