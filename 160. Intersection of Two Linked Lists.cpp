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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, there can be no intersection
        if (!headA || !headB) return nullptr;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // Traverse both lists
        while (ptrA != ptrB) {
            // If ptrA reaches the end, redirect it to headB
            // Otherwise, move to the next node
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;

            // If ptrB reaches the end, redirect it to headA
            // Otherwise, move to the next node
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // After the loop, either ptrA == ptrB (intersection node)
        // or ptrA == ptrB == nullptr (no intersection)
        return ptrA;
    }
};