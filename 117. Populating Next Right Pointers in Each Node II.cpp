#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root; // Pointer to traverse the current level

        while (curr) {
            Node dummy(0);      // Dummy head for the next level
            Node* tail = &dummy; // Tail pointer to build the next level's list

            // Traverse the current level using the 'next' pointers
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // Move to the next node in the current level
            }

            // Once the level is finished, jump to the start of the next level
            curr = dummy.next;
        }

        return root;
    }
};