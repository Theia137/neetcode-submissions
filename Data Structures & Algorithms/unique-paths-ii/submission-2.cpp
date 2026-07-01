class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> grid(rows+1, vector<int>(cols+1, 0));

        for(int r=1; r<=rows; r++){
            for(int c=1; c<=cols; c++){
                if(r == 1 && c == 1){
                    if(obstacleGrid[r-1][c-1]){
                        grid[r][c] = 0;
                    }
                    else{
                        grid[r][c] = 1;
                    }
                }
                else{
                    if(obstacleGrid[r-1][c-1]){
                        grid[r][c] = 0;
                    }
                    else{
                        grid[r][c] = grid[r-1][c] + grid[r][c-1];
                    }
                }
            }
        }
        return grid[rows][cols];
    }
};