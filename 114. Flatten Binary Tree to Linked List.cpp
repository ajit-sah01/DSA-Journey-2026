class Solution {
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Step 1: Recurse to the rightmost parts first (Reverse Pre-order)
        flatten(root->right);
        flatten(root->left);

        // Step 2: Set the current node's right to the previously processed node
        root->right = prev;
        // Step 3: Ensure the left child is always null
        root->left = nullptr;

        // Step 4: Update 'prev' to the current node for the next step up the recursion
        prev = root;
    }
};