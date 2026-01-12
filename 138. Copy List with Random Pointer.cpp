#include <iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create interweaved list
        // Original: A -> B -> C
        // Result:   A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the copies
        curr = head;
        while (curr) {
            if (curr->random) {
                // The copy's random is the original's random's copy
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the two lists
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;

        while (curr) {
            // Link the copy
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            // Restore the original list
            curr->next = copyCurr->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};