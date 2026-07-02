class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int end = matrix.size()-1;
        while(st <= end){
            int mid = (st + end)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] > target){
                end = mid-1;
            }
            else if(matrix[mid][0] < target){
                if(mid<end){
                    if(matrix[mid+1][0] <= target){
                        st = mid+1;
                    }
                    else{
                        st = mid;
                        end = st;
                    }
                }
                else if(mid == end){
                    st = mid;
                    break;
                }
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
