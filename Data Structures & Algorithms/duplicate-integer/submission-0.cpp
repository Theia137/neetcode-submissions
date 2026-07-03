class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<pair<int, int>>container;
        for(int num : nums){
            for(int i=0; i<container.size(); i++){
                if(container[i].first == num){
                    return true;
                }
            }
            container.push_back(make_pair(num, 1));
        }
        return false;
    }
};