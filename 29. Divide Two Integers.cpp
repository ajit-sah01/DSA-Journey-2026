class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Work with positive values using long long
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        // Bitwise division
        while (dvd >= dvs)
        {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd)
            {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};
