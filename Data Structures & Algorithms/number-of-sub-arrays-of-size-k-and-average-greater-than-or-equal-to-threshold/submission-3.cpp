class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int cursum = 0;
        threshold *= k;
        for(int i=0; i<arr.size(); i++){
            cursum += arr[i];
            if(i>=k-1){
                if(cursum >= threshold){
                    ans += 1;
                }
                cursum -= arr[i-(k-1)];
            }
        }
        return ans;
    }
};