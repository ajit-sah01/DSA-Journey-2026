class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is technically symmetric
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base case: both are null, so they are mirrors
        if (!t1 && !t2) return true;

        // If only one is null, or values don't match, they aren't mirrors
        if (!t1 || !t2 || t1->val != t2->val) return false;

        // Recursively check:
        // 1. Left of T1 with Right of T2
        // 2. Right of T1 with Left of T2
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};