class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;
        for(string s : operations){
            if(s[0] == '+'){
                int top = arr.back();
                arr.pop_back();
                arr.insert(arr.end(), {top, top + arr.back()});
            }
            else if(s[0] == 'C'){
                arr.pop_back();
            }
            else if(s[0] == 'D'){
                arr.push_back(arr.back() * 2);
            }
            else{
                arr.push_back(stoi(s));
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};