class Solution {
public:
    queue<tuple<int, int, int>> q;
    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    int maxdepth = 0;
    int m, n;

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({0, i, j});
                }
            }
        } 

        if(q.empty()){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }    
            return 0;
        }

        while(!q.empty()){
            int curdepth = get<0>(q.front());
            int y = get<1>(q.front());
            int x = get<2>(q.front());
            q.pop();
            maxdepth = max(maxdepth, curdepth);

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0<=ny && ny<m && 0<=nx && nx<n && grid[ny][nx] == 1){
                    grid[ny][nx] = 2;
                    q.push({curdepth+1, ny, nx});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }    
        return maxdepth;
    }
};
