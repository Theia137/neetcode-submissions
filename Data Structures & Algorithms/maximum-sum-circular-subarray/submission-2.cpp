class Solution {
public:
    queue<pair<int, int>> q;

    int maxSubarraySumCircular(vector<int>& nums) {
        int size = nums.size();
        int st_idx = 0;
        int cur_idx = 0;
        int cursum = 0;
        int maxsum = -30001;

        while(st_idx < size){
            if(cur_idx >= st_idx + size){
                st_idx += 1;
                cur_idx = st_idx;
                cursum = 0;
            }
            if(cursum + nums[cur_idx % size] >= nums[cur_idx % size]){
                cursum = cursum + nums[cur_idx % size];
                maxsum = max(maxsum, cursum);
            }
            else if(cursum + nums[cur_idx % size] < nums[cur_idx % size]){
                st_idx = cur_idx;
                if(st_idx >= size){
                    break;
                }
                cursum = nums[st_idx];
                maxsum = max(maxsum, cursum);
            }
            cur_idx += 1;
        }
        return maxsum;
    }
};