class Solution {
public:
    // Global or pass-by-reference map to track original -> clone mapping
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        // Base case: if the input node is null
        if (!node) {
            return nullptr;
        }

        // If the node has already been cloned, return the cloned instance
        if (copies.find(node) != copies.end()) {
            return copies[node];
        }

        // Create the clone for the current node
        // Note: we don't copy the neighbors yet to avoid infinite recursion
        Node* clone = new Node(node->val);
        copies[node] = clone;

        // Iterate through the neighbors of the original node
        for (Node* neighbor : node->neighbors) {
            // Recursively clone each neighbor and add to the cloned node's neighbors list
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};