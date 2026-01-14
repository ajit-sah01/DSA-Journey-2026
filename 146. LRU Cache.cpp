#include <vector>
#include <cstring>

// Standard fast I/O block for Competitive Programming
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class LRUCache {
private:
    // A simple struct to hold our data
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
    };

    // Direct mapping for keys (0 to 10000)
    // Faster than unordered_map because there is no hashing calculation.
    Node* lookup[10001];

    // Pre-allocated memory pool.
    // Capacity is max 3000. We need 3000 nodes + 2 sentinels (head/tail).
    Node pool[3002];

    Node* head;
    Node* tail;
    int capacity;
    int used; // Tracks how many nodes from the pool are currently active

    // Inline helper: Remove node from its current position
    inline void detach(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Inline helper: Insert node right after head
    inline void attach(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), used(0) {
        // Initialize lookup table with nulls using memset (very fast)
        std::memset(lookup, 0, sizeof(lookup));

        // Assign Head and Tail from the beginning of our pool
        head = &pool[0];
        tail = &pool[1];

        // Link Head and Tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // Direct array access (no hash overhead)
        Node* node = lookup[key];

        if (!node) return -1;

        // Move the accessed node to the front (MRU)
        detach(node);
        attach(node);

        return node->val;
    }

    void put(int key, int value) {
        Node* node = lookup[key];

        if (node) {
            // Case 1: Key already exists. Update value and move to front.
            node->val = value;
            detach(node);
            attach(node);
        } else {
            if (used < capacity) {
                // Case 2: New key, and we have space in our pre-allocated pool.
                // We take the next free slot from the pool (index 2 onwards).
                node = &pool[2 + used];
                used++;

                node->key = key;
                node->val = value;
                lookup[key] = node;
                attach(node);
            } else {
                // Case 3: Cache is full. Evict the LRU (node before tail).
                // Instead of deleting, we RECYCLE this node structure.
                node = tail->prev;

                // 1. Remove the old key mapping
                lookup[node->key] = nullptr;

                // 2. Overwrite node with new data
                node->key = key;
                node->val = value;
                lookup[key] = node; // Map new key to this recycled node

                // 3. Move this recycled node to the front
                detach(node);
                attach(node);
            }
        }
    }
};