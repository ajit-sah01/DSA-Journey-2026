#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: If the node is null, height is 0
        if (!root) return 0;

        // Recursively find the depth of left and right subtrees
        // The max function is highly optimized in C++
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};