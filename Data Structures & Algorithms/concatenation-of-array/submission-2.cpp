class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr;
        for(int i=0; i<2; i++){
            for(int elem : nums){
                arr.push_back(elem);
            }
        }
        return arr;
    }
};