class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Scenario 1: Both nodes are null
        if (!p && !q) {
            return true;
        }

        // Scenario 2: One is null or Scenario 3: Values differ
        if (!p || !q || p->val != q->val) {
            return false;
        }

        // Scenario 4: Values are same, check children recursively
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};