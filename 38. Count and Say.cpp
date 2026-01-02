class Solution
{
public:
    string calc(const string &s)
    {
        string ans = "";
        int n = s.size();
        int count = 1;
        char prev = s[0];

        for (int i = 1; i < n; i++)
        {
            if (s[i] == prev)
            {
                count++;
            }
            else
            {
                ans += to_string(count);
                ans.push_back(prev);
                count = 1;
                prev = s[i];
            }
        }

        // last run
        ans += to_string(count);
        ans.push_back(prev);

        return ans;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        return calc(prev);
    }
};
