#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        return build(head, n);
    }

private:
    // Passing ListNode*& (pointer by reference) is faster than using a class member
    // because it keeps the pointer in a register during recursion.
    TreeNode* build(ListNode*& head, int n) {
        if (n <= 0) return nullptr;

        // Recursively build the left half
        TreeNode* left = build(head, n / 2);

        // Process the root
        TreeNode* root = new TreeNode(head->val);
        root->left = left;

        // Move the actual head pointer in the calling frame
        head = head->next;

        // Build the right half
        root->right = build(head, n - n / 2 - 1);

        return root;
    }
};