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
    ListNode* partition(ListNode* head, int x) {
        // Use stack-allocated dummy nodes for zero heap-allocation overhead
        ListNode lessHead(0);
        ListNode greaterHead(0);

        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Combine the two lists
        greater->next = nullptr; // Prevent cycles
        less->next = greaterHead.next;

        return lessHead.next;
    }
};

// Fast I/O Optimization
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();