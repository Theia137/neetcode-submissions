class Solution {
public:
    int oricolor;
    int chcolor;
    int m;
    int n;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        oricolor = image[sr][sc];
        chcolor = color;
        if(oricolor == chcolor){
            return image;
        }

        dfs(image, sr, sc, oricolor, chcolor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int y, int x, int oricolor, int chcolor){
        if(0<=y && y<m){
            if(0<=x && x<n){
                if(image[y][x] == oricolor){
                    image[y][x] = chcolor;
                    dfs(image, y+1, x, oricolor, chcolor);
                    dfs(image, y-1, x, oricolor, chcolor);
                    dfs(image, y, x+1, oricolor, chcolor);
                    dfs(image, y, x-1, oricolor, chcolor);
                }
                
            }
        }
        return;
    }
};