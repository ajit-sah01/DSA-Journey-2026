struct ListNode
{
    int val;
    ListNode *next;

    explicit ListNode(int x, ListNode *n = nullptr)
        : val(x), next(n) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0); // Sentinel node
        ListNode *tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            const int a = l1 ? l1->val : 0;
            const int b = l2 ? l2->val : 0;

            const int sum = a + b + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy.next;
    }
};
