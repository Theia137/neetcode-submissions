class Solution {
public:
    vector<int> arr;
    
    int climbStairs(int n) {
        arr.resize(n+1, 0);

        return dp(n);
    }

    int dp(int n){
        if(n == 1){
            arr[n] = 1;
            return 1;
        }
        if(n == 2){
            arr[n] = 2;
            return 2;
        }
        if(arr[n]!=0){
            return arr[n];
        }
        arr[n] = dp(n-1) + dp(n-2);
        return arr[n];
    }
};
