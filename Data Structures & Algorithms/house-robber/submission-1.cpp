class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.resize(n, 0);
        if(n>=1){
            ans[0] = nums[0];
        }
        if(n>=2){
            ans[1] = max(ans[0], nums[1]);
        }
        for(int i=2; i<n; i++){
            ans[i] = max(ans[i-2]+nums[i], ans[i-1]);
        }
        return ans[n-1];
    }
};
