class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = nums.size()-1;
        int i=0;
        int j=nums.size()-1;
        while(i<nums.size()){
            if(nums[i] == 0){
                swap(nums[i], nums[zero]);
                zero += 1;
                i = zero;
            }
            i += 1;
        }
        while(zero<=j){
            if(nums[j] == 2){
                swap(nums[j], nums[two]);
                two -= 1;
                j = two;
            }
            j -= 1;
        }
    }
};