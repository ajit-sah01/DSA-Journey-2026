class Solution
{
public:
    bool isUgly(int n)
    {
        // Base case: ugly numbers must be positive
        if (n <= 0)
            return false;

        // Repeatedly divide by the allowed prime factors
        // Division by 2
        while (n % 2 == 0)
        {
            n /= 2;
        }

        // Division by 3
        while (n % 3 == 0)
        {
            n /= 3;
        }

        // Division by 5
        while (n % 5 == 0)
        {
            n /= 5;
        }

        // If the remaining number is 1, it's an ugly number
        return n == 1;
    }
};