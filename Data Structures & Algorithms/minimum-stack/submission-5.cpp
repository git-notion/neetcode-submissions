class MinStack {
public:
    stack<int>v;
    stack<int>mins;
    MinStack() {
        v;
    }
    
    void push(int val) {
        v.push(val);
        if(mins.empty()){
            mins.push(val);
        }
        else {
            if(val<mins.top()){
                mins.push(val);
            }
            else {
                mins.push(mins.top());
            }
        }
    }
    
    void pop() {
        v.pop();
        mins.pop();
    }
    
    int top() {
        return v.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
