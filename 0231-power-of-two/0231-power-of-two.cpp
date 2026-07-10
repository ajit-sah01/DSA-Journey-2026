class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // // O(log n) approach
        // if (n <= 0)
        // {
        //     return false;
        // }
        // while (n % 2 == 0)
        // {
        //     n /= 2;
        // }
        // return n == 1;

       // // O(1) approach using bit manipulation
        return n > 0 && (n & (n - 1)) == 0;
    }
};