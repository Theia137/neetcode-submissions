class Solution {
public:
    vector<int> backtrack;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, 0, target);
        return ans;
    }

    void dfs(vector<int>&nums, int idx, int size, int target){
        if(size == target){
            ans.push_back(backtrack);
            return;
        }
        else{
            for(int i=idx; i<nums.size(); i++){
                if(nums[i] + size <= target){
                    backtrack.push_back(nums[i]);
                    dfs(nums, i, nums[i]+size, target);
                    backtrack.pop_back();
                }
            }
        }
    }
};
