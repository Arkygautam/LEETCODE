class MinStack {
public:

    stack<int> s1;
    stack<int> s2;

    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
    }
    
    void pop() {
        if(!s1.empty()){
            s1.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        int mini = INT_MAX;
        while(!s1.empty()){
            if(s1.top() < mini){
                mini = s1.top();
            }
            s2.push(s1.top());
            s1.pop();
        }

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }


        return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */