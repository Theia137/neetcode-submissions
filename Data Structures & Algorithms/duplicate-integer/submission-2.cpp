class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> containers;
        for(int num : nums){
            if(containers.find(num) != containers.end()){
                return true;
            }
            containers.insert(num);
        }
        return false;
    }
};