class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> container;
        for(char alpha : s){
            container[alpha] += 1;
        }
        for(char beta : t){
            if(container[beta] == 0){
                return false; 
            }
            else{
                container[beta] -= 1;
            }
        }
        
        for(auto it=container.begin(); it!=container.end(); it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
