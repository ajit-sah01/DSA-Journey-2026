class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr; // Cut the list into two halves

        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Merge the two halves (Interleaving)
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};