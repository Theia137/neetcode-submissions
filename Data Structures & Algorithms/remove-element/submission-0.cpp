class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int j = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if(nums[i] != val){
                k += 1;
                nums[j] = nums[i];
                j += 1;
            }
        }
        for (int i=j; i<n; i++){
            nums[j] = '_';
        }
        return k;
    }
};