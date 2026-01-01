class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Fast rejection
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int rev = 0;

        // Reverse only half the digits
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        // Even length: x == rev
        // Odd length : x == rev / 10
        return x == rev || x == rev / 10;
    }
};
