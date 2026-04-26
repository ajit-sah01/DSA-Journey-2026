class Solution
{
private:
    // Helper function to calculate the sum of the squares of digits
    int getNext(int n)
    {
        int totalSum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNext(n);

        // Loop until fast reaches 1 (happy) or slow catches up to fast (cycle)
        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);          // Move slow by 1 step
            fast = getNext(getNext(fast)); // Move fast by 2 steps
        }

        // If fast reached 1, it's a happy number
        return fast == 1;
    }
};