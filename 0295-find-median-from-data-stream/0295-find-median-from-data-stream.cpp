#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    // Smaller half -> Max Heap
    priority_queue<int> left;

    // Larger half -> Min Heap
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        
    }

    void addNum(int num) {

        // Step 1: Insert into left
        left.push(num);

        // Step 2: Move largest of left to right
        right.push(left.top());
        left.pop();

        // Step 3: Balance heaps
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return ((long long)left.top() + right.top()) / 2.0;
    }
};