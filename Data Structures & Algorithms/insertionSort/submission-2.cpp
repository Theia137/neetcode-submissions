// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;
        for(int i=0; i<pairs.size(); i++){
            Pair front = pairs[i];
            int front_val = front.key;
            int j = i;
            j = i-1;
            while(j>=0 && pairs[j].key > front_val){
                pairs[j+1] = pairs[j];
                j = j-1; 
            }
            pairs[j+1] = front;
            ans.push_back(pairs);
        } 
        return ans;
    }
};
