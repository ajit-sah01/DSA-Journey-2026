class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            // Step 1: Process Root
            ans.push_back(node->val);

            // Step 2: Push Left then Right (so Right is processed first)
            // This creates the Root -> Right -> Left pattern
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        // Step 3: Reverse the entire vector to get Left -> Right -> Root
        reverse(ans.begin(), ans.end());
        return ans;
    }
};