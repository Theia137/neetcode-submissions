class Solution {
public:
    priority_queue<int, vector<int>> pq;

    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones){
            pq.push(stone);
        }

        while(true){
            if(pq.empty()){
                return 0;
            }
            if(pq.size() == 1){
                return pq.top();
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int z = y-x;
            if(z!=0){
                pq.push(z);
            }
        }
    }
};
