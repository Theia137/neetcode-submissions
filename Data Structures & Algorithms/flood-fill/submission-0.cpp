class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> visit;
    int oricolor;
    int chcolor;
    int m;
    int n;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        ans.resize(m, vector<int>(n));
        visit.resize(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = image[i][j];
                visit[i][j] = 0;
            }
        }
        oricolor = ans[sr][sc];
        chcolor = color;
        visit[sr][sc] = 1;
        dfs(sr, sc, oricolor, chcolor);
        return ans;
    }

    void dfs(int y, int x, int oricolor, int chcolor){
        ans[y][x] = chcolor;

        vector<int> arry = {-1, 1, 0, 0};
        vector<int> arrx = {0, 0, -1, 1};

        for(int i=0; i<4; i++){
            int ny = y + arry[i];
            int nx = x + arrx[i];

            if(0<=ny && ny<m){
                if(0<=nx && nx<n){
                    if(visit[ny][nx] == 0){
                        if(ans[ny][nx] == oricolor){
                            visit[ny][nx] = 1;
                            dfs(ny, nx, oricolor, chcolor);
                        }
                    }
                }
            }
        }
        return;
    }
};