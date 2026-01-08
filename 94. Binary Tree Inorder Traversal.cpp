#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // 1. Reach the leftmost node of the current node
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // 2. Current must be NULL at this point, so we pop from stack
            curr = s.top();
            s.pop();

            // 3. Add the node value to result
            result.push_back(curr->val);

            // 4. We have visited the node and its left subtree.
            // Now, it's the right subtree's turn.
            curr = curr->right;
        }

        return result;
    }
};