/**
* Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            // Check if current node is the start of a duplicate sequence
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev to the node AFTER the last duplicate
                prev->next = head->next;
            } else {
                // No duplicates for this value, move prev forward
                prev = prev->next;
            }
            // Move head forward to continue checking
            head = head->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Clean up the dummy node memory
        return result;
    }
};