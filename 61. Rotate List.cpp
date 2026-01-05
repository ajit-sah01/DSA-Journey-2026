class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length and tail
        int length = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }

        // Step 2: Reduce k
        k = k % length;
        if (k == 0)
            return head;

        // Step 3: Make list circular
        tail->next = head;

        // Step 4: Find new tail
        int stepsToNewTail = length - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewTail; i++)
        {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
