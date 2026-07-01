class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int num = 0;
            int j = i;
            while(j!=0){
                num += (j & 1);
                j = (j>>1);
            }
            ans.push_back(num);
        }
        return ans;
    }
};
