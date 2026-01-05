class Solution
{
public:
    bool isNumber(string s)
    {
        bool seenDigit = false;    // any digit before 'e'
        bool seenDot = false;      // '.'
        bool seenExp = false;      // 'e' or 'E'
        bool digitAfterExp = true; // digits after exponent

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                seenDigit = true;
                if (seenExp)
                    digitAfterExp = true;
            }
            else if (c == '+' || c == '-')
            {
                // sign must be at start or just after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.')
            {
                // dot cannot appear after exponent or more than once
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E')
            {
                // exponent must appear once and only after a digit
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                digitAfterExp = false; // must see digit later
            }
            else
            {
                return false; // invalid character
            }
        }

        return seenDigit && digitAfterExp;
    }
};
