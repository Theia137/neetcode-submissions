class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int elem : nums){
            int temp = max(elem + a, b);
            a = b;
            b = temp;
        }
        return b;
    }
};
