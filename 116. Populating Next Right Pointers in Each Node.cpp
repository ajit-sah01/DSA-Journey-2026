#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    Node* connect(Node* root) {
        // Extreme early exit
        if (!root || !root->left) return root;

        Node* levelPtr = root;

        // Process level by level
        while (levelPtr->left) {
            Node* curr = levelPtr;

            // Inner loop: we use the next pointers already established in the previous level
            while (curr) {
                // Connection 1: Interior of the current parent
                curr->left->next = curr->right;

                // Connection 2: Bridge to the next parent
                if (curr->next) {
                    curr->right->next = curr->next->left;
                } else {
                    // No more nodes in this level, break inner loop early
                    break;
                }
                curr = curr->next;
            }
            // Move to the next level down
            levelPtr = levelPtr->left;
        }

        return root;
    }
};