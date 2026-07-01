class Solution {
public:
    vector<int> memo;

    vector<int> countBits(int n) {
        vector<int> ans;
        memo.resize(n+1, 0);
        
        int i = 0;
        while(i!=(n+1)){
            ans.push_back(dp(i));
            i += 1;
        }
        return ans;
    }

    int dp(int n){
        if(n == 0){
            memo[0] = 0;
            return memo[n];
        }
        if(n == 1){
            memo[1] = 1;
            return memo[n];
        }
        if(memo[n]!=0){
            return memo[n];
        }
        memo[n] = memo[n-(1<<getmax(n))] + 1;
        return memo[n];
    }
    
    
    int getmax(int n){
        int ans = 0;
        n = (n>>1);
        while(n!=0){
            ans += 1;
            n = (n>>1);
        }
        return ans;
    }
};
