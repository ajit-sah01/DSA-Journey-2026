class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // BFS uses a queue to keep track of nodes at the current level
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // If we find the first leaf node, it's the shortest path
                if (curr->left == nullptr && curr->right == nullptr) {
                    return depth;
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // Move to the next level
            depth++;
        }

        return depth;
    }
};