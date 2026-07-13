class Solution {
public:
    unordered_map<int, vector<int>> hashmap;

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]].push_back(i);
        }
        int prev_val = 0;
        int cur_val = 0;
        for(auto mapp : hashmap){
            for(int i=1; i<mapp.second.size(); i++){
                if(mapp.second[i] - mapp.second[i-1] <= k){
                    return true;
                }
            }
        }   
        return false;
    }
};