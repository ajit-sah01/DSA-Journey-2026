#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        // Since we know the maximum number of operands is tokens.size(),
        // we use a fixed-size array on the stack for maximum speed.
        int stack[10001];
        int top = -1;

        for (const std::string& s : tokens) {
            // Check if the token is an operator
            // We look at the back() to handle negative numbers like "-11" correctly
            if (s.size() > 1 || isdigit(s[0])) {
                // It's a number: Convert and push to stack
                stack[++top] = std::stoi(s);
            } else {
                // It's an operator: Pop two operands
                int b = stack[top--];
                int a = stack[top--];

                switch (s[0]) {
                    case '+': stack[++top] = a + b; break;
                    case '-': stack[++top] = a - b; break;
                    case '*': stack[++top] = a * b; break;
                    case '/': stack[++top] = a / b; break;
                }
            }
        }
        return stack[0];
    }
};