class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
    // int min_val = std::numeric_limits<int>::max();
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(min_stk.empty()) min_stk.push(val);
        else
        {
            if(val < min_stk.top()) min_stk.push(val);
            else min_stk.push(min_stk.top());
        }
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
