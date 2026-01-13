/**
* Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // While fast can move at least two steps forward
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps

            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }

        // If we reach the end of the list
        return false;
    }
};