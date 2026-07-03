class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> container;
        
        for(int i=0; i<n; i++){
            int left = target - nums[i];
            if(container.find(left) != container.end()){
                return {container[left], i};
            }
            else{
                container.insert({nums[i], i});
            }
        }
        return {};
    }
};
