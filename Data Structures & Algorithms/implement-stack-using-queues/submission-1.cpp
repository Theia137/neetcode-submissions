class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        int size = q1.size();
        q1.push(x);
        q2.push(x);
        if(!this->empty()){
            for(int i=0; i<size; i++){
                q2.push(q2.front());
                q2.pop();
            }
        }
    }
    
    int pop() {
        if(!this->empty()){
            int size = q1.size();
            for(int i=0; i<size; i++){
                q1.push(q1.front());
                q1.pop();
            }
            int ans = q2.front();
            q1.pop();
            q2.pop();
            return ans;
        }
        return -1;
    }
    
    int top() {
        if(!this->empty()){
            return q2.front();
        }
        return -1;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */