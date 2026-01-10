class Solution {
public:
    void findPaths(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (!node) return;

        // Add current node to the path
        currentPath.push_back(node->val);

        // Check if it's a leaf node and the sum matches
        if (!node->left && !node->right && targetSum == node->val) {
            allPaths.push_back(currentPath);
        } else {
            // Recurse to children with updated targetSum
            findPaths(node->left, targetSum - node->val, currentPath, allPaths);
            findPaths(node->right, targetSum - node->val, currentPath, allPaths);
        }

        // Backtrack: remove current node before going back up the tree
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, allPaths);
        return allPaths;
    }
};