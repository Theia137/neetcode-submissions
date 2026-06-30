class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutive = 0;
        int max = 0;
        for (int i=0; i<size(nums); i++){
            if(nums[i] == 1){
                consecutive += 1;
                if(max < consecutive){
                    max = consecutive;
                }
            }
            else{
                consecutive = 0;
            }
        }
        return max;
    }
};