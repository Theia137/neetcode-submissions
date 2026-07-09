class Solution {
public:
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visit;
    vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int m, n;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visit.resize(m, vector<int>(n, 0));

        if(grid[0][0] || grid[m-1][n-1]){
            return -1;
        }

        int ans = 1;
        visit[0][0] = 1;
        q.push({1, 0, 0});

        while(!q.empty()){
            int depth = get<0>(q.front());
            int y = get<1>(q.front());
            int x = get<2>(q.front());
            if(y == m-1 && x == n-1){
                return depth;
            }
            q.pop();

            for(int i=0; i<8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0<=ny && ny<m && 0<=nx && nx<n && visit[ny][nx] == 0 && grid[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    q.push({depth + 1, ny, nx});
                }
            }
        }
        return -1;
    }
};