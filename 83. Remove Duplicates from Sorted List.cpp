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

        ListNode* current = head;

        // Traverse the list until the last node
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Duplicate found: link current to the node after the duplicate
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Optional: free memory of the removed node
            } else {
                // No duplicate: move to the next node
                current = current->next;
            }
        }

        return head;
    }
};