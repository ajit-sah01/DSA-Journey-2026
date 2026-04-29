#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();


class Solution {
    // Using a stack-allocated array for the map because the range is small [-3000, 3000]
    // This is faster than unordered_map due to better cache locality.
    int inMap[6001];
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i] + 3000] = i; // Offset by 3000 to handle negative values
        }
        int preIdx = 0;
        return solve(preorder, 0, inorder.size() - 1, preIdx);
    }
    TreeNode* solve(vector<int>& preorder, int inStart, int inEnd, int& preIdx) {
        if (inStart > inEnd) return nullptr;
        // Pick current node from preorder traversal using preIdx
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        // Find the index of this node in Inorder traversal
        int inIdx = inMap[rootVal + 3000];
        // Recursively build left and right subtrees
        // Important: Build Left first because preorder is (Root, Left, Right)
        root->left = solve(preorder, inStart, inIdx - 1, preIdx);
        root->right = solve(preorder, inIdx + 1, inEnd, preIdx);
        return root;
    }
};
