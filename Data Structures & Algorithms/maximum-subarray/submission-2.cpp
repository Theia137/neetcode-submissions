class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curnum = 0;
        int maxnum = -1001;
        for(int i=0; i<nums.size(); i++){
            curnum = max(curnum + nums[i], nums[i]);
            maxnum = max(maxnum, curnum);
        }
        return maxnum;
    }
};
