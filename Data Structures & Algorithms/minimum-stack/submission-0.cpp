class MinStack {
public:
    vector<int> ans;

    MinStack() {

    }
    
    void push(int val) {
        ans.push_back(val);
    }
    
    void pop() {
        if(!ans.empty()){
            ans.pop_back();
        }
    }
    
    int top() {
        if(!ans.empty()){
            return ans.back();
        }
        return -1;
    }
    
    int getMin() {
        if(!ans.empty()){
            int min = pow(2, 31) - 1;
            for(int answer : ans){
                if(answer < min){
                    min = answer;
                }
            }
            return min;
        }
        else{
            return -1;
        }
    }
};
