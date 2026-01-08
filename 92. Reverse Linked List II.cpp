class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node simplifies cases where 'left' is the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // 1. Move 'prev' to the node just before the 'left' position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 2. 'curr' is the first node to be reversed
        ListNode* curr = prev->next;

        // 3. Perform the reversal for the specified range
        // We move the 'forw' node to the position after 'prev' one by one
        for (int i = 0; i < right - left; ++i) {
            ListNode* forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};