class Solution {
public:
    int maxArea = 0;
    int curArea = 0;
    int m, n;
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    curArea = 0;
                    dfs(grid, i, j);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int y, int x){
        if(y<0 || y>=m || x<0 || x>=n || grid[y][x]==0){
            return;
        }
        curArea += 1;
        grid[y][x] = 0;
        
        dfs(grid, y+1, x);
        dfs(grid, y-1, x);
        dfs(grid, y, x+1);
        dfs(grid, y, x-1);
    }
};
