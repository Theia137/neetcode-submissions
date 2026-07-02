class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        points = sort(points, 0, points.size()-1);
        vector<vector<int>> ans(points.begin(), points.begin()+k);
        return ans;
    }

    float dist(vector<int> point){
        int x = point[0];
        int y = point[1];
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    vector<vector<int>> sort(vector<vector<int>>& points, int st, int big){
        if(st >= big){
            return points;
        }
        float pivotdist = dist(points[big]);
        int low = st;
        int high = big - 1;
        while(low <= high){
            if(dist(points[low]) <= pivotdist){
                low += 1;
            }
            else if(dist(points[high]) >= pivotdist){
                high -= 1;
            }
            else{
                swap(points[low], points[high]);
                low += 1;
                high -= 1;
            }
        }
        swap(points[low], points[big]);
        sort(points, st, low-1);
        sort(points, low+1, big);
        return points;
    }
};
