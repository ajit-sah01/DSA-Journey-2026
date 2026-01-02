class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    int n;

    void dfs(const vector<int> &candidates, int target, int start)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < n; i++)
        {
            int val = candidates[i];
            if (val > target)
                break; // hard prune

            path.push_back(val);
            dfs(candidates, target - val, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        dfs(candidates, target, 0);
        return res;
    }
};
