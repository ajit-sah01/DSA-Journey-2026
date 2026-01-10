class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1. If the node is null, no path exists
        if (root == nullptr) {
            return false;
        }

        // 2. Check if this is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // 3. Subtract the current value and recurse down
        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};