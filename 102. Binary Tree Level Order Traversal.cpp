#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        ans.reserve(32); // Pre-reserve for a deep tree to avoid reallocations

        // Using a vector as a manual queue is often faster than std::queue
        vector<TreeNode*> q;
        q.reserve(2000); // Constraint says max 2000 nodes
        q.push_back(root);

        int head = 0;
        while (head < q.size()) {
            int size = q.size() - head;
            vector<int> level;
            level.reserve(size); // Avoid resizing the inner vector

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q[head++];
                level.push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            ans.push_back(std::move(level)); // Move rather than copy
        }

        return ans;
    }
};