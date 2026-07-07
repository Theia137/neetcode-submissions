class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        this->cap = k;
        for(int elem : nums){
            pq.push(elem);
            if(pq.size() > cap){
                pq.pop();
            }
        }    
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > cap){
            pq.pop();
        }
        return pq.top();
    }
};
