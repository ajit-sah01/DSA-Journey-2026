class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* lastSorted = head; // The last node of the sorted part
        ListNode* curr = head->next; // The node to be inserted

        while (curr) {
            if (lastSorted->val <= curr->val) {
                // Already in the right spot, just move the boundary
                lastSorted = lastSorted->next;
            } else {
                // Find where to insert curr starting from dummy
                ListNode* prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                // Move curr to be after prev
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }

        return dummy->next;
    }
};