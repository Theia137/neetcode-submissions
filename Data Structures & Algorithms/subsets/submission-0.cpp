class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = (1<<n);
        vector<vector<int>> ans(total);
        for(int i=1; i<total; i++){
            int bitnum = i;
            for(int j=0; j<n; j++){
                if(bitnum & 1){
                    ans[i].push_back(nums[j]);
                }
                bitnum = bitnum >> 1;
            }
        }
        return ans;
    }
};
