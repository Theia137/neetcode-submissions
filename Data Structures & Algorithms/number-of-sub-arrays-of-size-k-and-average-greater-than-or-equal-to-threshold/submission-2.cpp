class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        if(arr.size()<k){
            return ans;
        }
        int cursum = 0;
        for(int i=0; i<k; i++){
            cursum += arr[i];
        }
        float curavg = float(cursum/k);
        
        if(curavg >= threshold){
            ans += 1;
        }

        for(int i=k; i<arr.size(); i++){
            cursum = cursum + arr[i] - arr[i-k];
            curavg = float(cursum/k);
            if(curavg >= threshold){
                ans += 1;
            }    
        }
        return ans;
    }
};