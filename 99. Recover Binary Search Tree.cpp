class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr, *curr = root;
        
        while (curr) {
            if (!curr->left) {
                // Process node
                if (prev && curr->val < prev->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) pred = pred->right;

                if (!pred->right) {
                    pred->right = curr; // Create thread
                    curr = curr->left;
                } else {
                    pred->right = nullptr; // Break thread
                    // Process node
                    if (prev && curr->val < prev->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};