#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        // 1. Find max depth to pre-allocate result size
        int depth = getMaxDepth(root);
        vector<vector<int>> ans(depth);

        // 2. Fill the vectors using DFS
        fillLevels(root, 0, depth, ans);

        return ans;
    }

private:
    int getMaxDepth(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getMaxDepth(node->left), getMaxDepth(node->right));
    }

    void fillLevels(TreeNode* node, int currentLevel, int maxDepth, vector<vector<int>>& ans) {
        if (!node) return;

        // Bottom-up index: maxDepth - 1 - currentLevel
        ans[maxDepth - 1 - currentLevel].push_back(node->val);

        fillLevels(node->left, currentLevel + 1, maxDepth, ans);
        fillLevels(node->right, currentLevel + 1, maxDepth, ans);
    }
};