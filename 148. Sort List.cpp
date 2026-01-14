class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Get the total length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // 2. Iteratively merge sub-lists of size 1, 2, 4, 8...
        for (int size = 1; size < length; size <<= 1) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                // Left part of merge
                ListNode* left = curr;
                ListNode* right = split(left, size);
                // Remaining part for the next iteration
                curr = split(right, size);

                // Merge left and right, and attach to the sorted chain
                prev->next = merge(left, right);

                // Move prev to the end of the merged sub-list
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }
        return dummy.next;
    }

private:
    // Splits the list into two: first 'n' nodes and the rest.
    // Returns the head of the second part.
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head && i < n; i++) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr; // Disconnect the first part
        return second;
    }

    // Standard merge of two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};