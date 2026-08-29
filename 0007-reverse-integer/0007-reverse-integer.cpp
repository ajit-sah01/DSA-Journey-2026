// class Solution
// {
// public:
//     int reverse(int n)
//     {
//         int reverseNum = 0;
//         while (n != 0)
//         {
//             int dig = n % 10;

//             if(reverseNum > INT_MAX/10 || reverseNum < INT_MIN/10){
//                 return 0;
//             }

//             reverseNum = reverseNum * 10 + dig;

//             n = n / 10;
//         }
//         return reverseNum;
//     }
// };


class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check overflow before rev * 10 + digit
            if (rev > INT_MAX / 10 ||
                (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (rev < INT_MIN / 10 ||
                (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10 + digit;
        }

        return rev;
    }
};