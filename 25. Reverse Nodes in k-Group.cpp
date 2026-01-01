/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        // Dummy node simplifies head handling
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroup = &dummy;

        while (true)
        {
            // Find kth node
            ListNode *kth = prevGroup;
            for (int i = 0; i < k && kth; ++i)
            {
                kth = kth->next;
            }
            if (!kth)
                break; // Not enough nodes to reverse

            ListNode *nextGroup = kth->next;

            // Reverse current k-group
            ListNode *prev = nextGroup;
            ListNode *curr = prevGroup->next;

            while (curr != nextGroup)
            {
                ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Reconnect reversed group
            ListNode *newGroupHead = prev;
            ListNode *newGroupTail = prevGroup->next;

            prevGroup->next = newGroupHead;
            prevGroup = newGroupTail;
        }

        return dummy.next;
    }
};
