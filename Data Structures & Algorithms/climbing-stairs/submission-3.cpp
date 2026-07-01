class Solution {
public:
    int climbStairs(int n) {
        arr.resize(n+1, 0);
        return dp(n);
    }
    vector<int> arr;

    int dp(int n){
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(arr[n] != 0){
            return arr[n];
        }
        arr[n] = dp(n-1) + dp(n-2);
        return arr[n];
    }
};
