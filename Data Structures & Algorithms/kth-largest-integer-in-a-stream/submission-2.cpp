class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int elem : nums){
            if(pq.size() < k){
                pq.push(elem);
            }
            else{
                pq.push(elem);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < cap){
            pq.push(val);
            return pq.top();
        }
        else{
            pq.push(val);
            pq.pop();
            return pq.top();
        }
    }
};
