#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    // Memoization table to store results for range {start, end}
    map<pair<int, int>, vector<TreeNode*>> memo;

    vector<TreeNode*> buildTrees(int start, int end) {
        // Base case: if range is invalid, return a list containing nullptr
        if (start > end) {
            return {nullptr};
        }
        
        // Check memoization table
        if (memo.count({start, end})) {
            return memo[{start, end}];
        }

        vector<TreeNode*> allTrees;

        // Iterate through each number as the root
        for (int i = start; i <= end; ++i) {
            // Generate all possible left and right subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        return memo[{start, end}] = allTrees;
    }
};