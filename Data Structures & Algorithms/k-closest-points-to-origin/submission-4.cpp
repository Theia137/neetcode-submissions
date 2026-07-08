class Solution {
public:
    struct cmp{
        bool operator()(vector<int>&p1, vector<int>&p2){
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1]; 
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(vector<int> point : points){
            pq.push(point);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
