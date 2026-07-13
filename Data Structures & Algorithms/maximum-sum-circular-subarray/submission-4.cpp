class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = -30001;
        int curmax = 0;
        int minsum = 30001;
        int curmin = 0;
        int totalsum = 0;

        for(int i=0; i<nums.size(); i++){
            curmax = max(curmax + nums[i], nums[i]); // -2 -3 -1
            curmin = min(curmin + nums[i], nums[i]); // -2 -5 -6
            maxsum = max(maxsum, curmax);            // -2 -2 -1
            minsum = min(minsum, curmin);            // -2 -5 -6
            totalsum += nums[i];                     // -2 -5 -6
        }
        if(totalsum == minsum){
            return maxsum;
        }
        return max(maxsum, totalsum - minsum);
    }
};