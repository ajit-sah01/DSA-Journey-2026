#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 != 0)
            return false; // odd length cannot be valid

        char stack[10000];
        int top = -1;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack[++top] = c;
            }
            else
            {
                if (top < 0)
                    return false;

                char open = stack[top--];
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '['))
                {
                    return false;
                }
            }
        }
        return top == -1;
    }
};
