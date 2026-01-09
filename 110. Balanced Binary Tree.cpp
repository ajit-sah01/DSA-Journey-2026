#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If checkHeight returns -1, it means the tree is unbalanced
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Early exit

        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Early exit

        // If height difference > 1, this node is unbalanced
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return actual height to the parent
        return 1 + std::max(leftHeight, rightHeight);
    }
};