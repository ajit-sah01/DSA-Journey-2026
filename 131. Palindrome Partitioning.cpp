
class Solution
{
public:
    //// Check PaliDrome
    bool isPali(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    //// Get all Parts
    void getAllParts(string s,
                     vector<string> &partitions,
                     vector<vector<string>> &ans)
    {
        short n = s.size();
        if (n == 0)
        {
            ans.push_back(partitions);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            string part = s.substr(0, i + 1);

            if (isPali(part))
            {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};
