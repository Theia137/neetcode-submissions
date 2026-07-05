class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while(true){
            if(i<m && j<n){
                if(nums1[i] < nums2[j]){
                    ans.push_back(nums1[i]);
                    i += 1;
                }
                else{
                    ans.push_back(nums2[j]);
                    j += 1;
                }
            }
            else if(i<m){
                while(i<m){
                    ans.push_back(nums1[i]);
                    i += 1;
                }
            }
            else if(j<n){
                while(j<n){
                    ans.push_back(nums2[j]);
                    j += 1;
                }
            }
            else{
                break;
            }
        }
        nums1 = move(ans);
    }
};