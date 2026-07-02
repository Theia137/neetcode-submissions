class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int end = matrix.size()-1;
        int cols = matrix[0].size()-1;

        if (target < matrix[0][0] || target > matrix[end][cols]) {
            return false;
        }

        while(st <= end){
            int mid = (st + end)/2;
            if(matrix[mid][0] > target){
                end = mid-1;
            }
            else if(matrix[mid][cols] < target){
                st = mid+1;
            }
            else{
                st = mid;
                break;
            }
        }
        return searchlinear(matrix, st, target);
    }

    bool searchlinear(vector<vector<int>>& matrix, int index, int target){
        int st = 0;
        int end = matrix[0].size()-1;
        while(st <= end){
            int mid = (st+end)/2;
            if(matrix[index][mid] == target){
                return true;
            }
            else{
                if(st == end){
                    break;
                }
                else if(matrix[index][mid] > target){
                    end = mid - 1;
                }
                else if(matrix[index][mid] < target){
                    st = mid + 1;
                }
            }
        }
        return false;
    }
};