class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> container(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            container[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int elem : container[cur]){
                if(indegree[elem] > 0){
                    indegree[elem] -= 1;
                    if(indegree[elem] == 0){
                        q.push(elem);
                    }
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] != 0){
                return false;
            }
        }
        return true;
    }
};
