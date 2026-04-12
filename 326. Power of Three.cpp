class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // Powers of three must be positive
        if (n <= 0)
            return false;

        // Keep dividing by 3 as long as there is no remainder
        while (n % 3 == 0)
        {
            n /= 3;
        }

        // If n is reduced to 1, it's a power of three
        return n == 1;
    }
};