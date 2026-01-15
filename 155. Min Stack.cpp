class MinStack {
private:
    // We use long long to prevent overflow during subtraction
    stack<long long> s;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(0LL);
            minVal = val;
        } else {
            // Push the difference (val - current min)
            s.push((long long)val - minVal);
            // If val is the new minimum, update minVal
            if (val < minVal) minVal = val;
        }
    }

    void pop() {
        long long diff = s.top();
        s.pop();

        // If diff < 0, it means the popped element was the minimum
        // We must restore the previous minimum
        if (diff < 0) {
            minVal = minVal - diff;
        }
    }

    int top() {
        long long diff = s.top();
        if (diff > 0) {
            return (int)(diff + minVal);
        } else {
            return (int)minVal;
        }
    }

    int getMin() {
        return (int)minVal;
    }
};