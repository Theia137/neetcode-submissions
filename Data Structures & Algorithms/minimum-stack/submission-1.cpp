class MinStack {
public:
    stack<int> stck;

    MinStack() {
        
    }
    
    void push(int val) {
        stck.push(val);
    }
    
    void pop() {
        stck.pop();
    }
    
    int top() {
        if(!stck.empty()){
            return stck.top();
        }
        else{
            return -1;
        }
    }
    
    int getMin() {
        if(!stck.empty()){
            int minn = stck.top();
            stack<int> tmp;
            while(stck.size()){
                minn = min(minn, stck.top());
                tmp.push(stck.top());
                stck.pop();
            }
            while(tmp.size()){
                stck.push(tmp.top());
                tmp.pop();
            }
            return minn;
        }
        else{
            return -1;
        }
    }
};
