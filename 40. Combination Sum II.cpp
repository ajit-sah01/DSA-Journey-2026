class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(const vector<int> &candidates, int target, int start)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            // Skip duplicates at the same depth
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break; // pruning

            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1); // no reuse
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};
