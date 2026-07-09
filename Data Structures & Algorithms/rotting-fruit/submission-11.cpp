class Solution {
public:
    queue<pair<int, int>> q;
    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    int m, n, fresh;
    int time;

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        fresh = 0;
        time = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh += 1;
                }
            }
        } 

        while(fresh>0 && !q.empty()){
            int length = q.size();
            for(int i=0; i<length; i++){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for(int j=0; j<4; j++){
                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    if(0<=ny && ny<m && 0<=nx && nx<n && grid[ny][nx] == 1){
                        fresh -= 1;
                        grid[ny][nx] = 2;
                        q.push({ny, nx});
                    }
                }
            }
            time += 1;
        }

        if(fresh > 0){
            return -1;
        }
        return time;
    }
};
