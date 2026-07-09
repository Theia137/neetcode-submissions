class Solution {
public:
    int num, m, n;
    int numIslands(vector<vector<char>>& grid) {
        num = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    num += 1;
                }
            }
        }
        return num;
    }

    void dfs(vector<vector<char>>& grid, int y, int x){
        if(y<0 || y>=m || x<0 || x>=n || grid[y][x] == '0'){
            return;
        }
        grid[y][x] = '0';
        dfs(grid, y+1, x);
        dfs(grid, y-1, x);
        dfs(grid, y, x+1);
        dfs(grid, y, x-1);
    }
};
