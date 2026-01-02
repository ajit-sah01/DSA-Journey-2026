class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxLen = 0;
        stack<int> st;
        st.push(-1); // Base for valid substring

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i); // Reset base
                }
                else
                {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};
