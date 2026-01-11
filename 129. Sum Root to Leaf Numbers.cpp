/**
* Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        // Form the number for the current path
        currentSum = currentSum * 10 + node->val;

        // If it's a leaf node, return the completed number
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Otherwise, continue down both branches and sum the results
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};