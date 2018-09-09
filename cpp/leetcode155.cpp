class MinStack {
public:
    /** initialize your data structure here. */
    int minn = INT_MAX;
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int x) {
        if (x <= minn) {
            s.push(minn);
            minn = x;
        }
        s.push(x);
    }
    
    void pop() {
        if (s.top() == minn) { s.pop(); minn = s.top(); }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */