#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Min-heap comparing node values
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        // Push the head of each non-empty list
        for (ListNode *node : lists)
        {
            if (node)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
            {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }

private:
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b) const
        {
            return a->val > b->val; // min-heap
        }
    };
};
