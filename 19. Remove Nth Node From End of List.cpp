class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i)
        {
            if (fast == nullptr)
                return dummy.next; // defensive guard
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete target node
        ListNode *target = slow->next;
        slow->next = target->next;

        // delete target; // enable only if ownership is clear

        return dummy.next;
    }
};
