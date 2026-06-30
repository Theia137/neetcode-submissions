class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            int max = 0;
            for(int j=i+1; j<n; j++){
                if(max < arr[j]){
                    max = arr[j];
                }
            }
            arr[i] = max;
        }
        arr[n-1] = -1;
        return arr;
    }
};