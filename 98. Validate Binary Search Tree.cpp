class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // Base case: an empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // The current node's value must be strictly within (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Recursively validate left and right subtrees with updated ranges
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};