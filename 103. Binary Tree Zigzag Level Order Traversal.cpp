#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        ans.reserve(32);

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size); // Pre-size the vector

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine position based on current direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(std::move(level));
            leftToRight = !leftToRight; // Flip the direction for the next level
        }

        return ans;
    }
};