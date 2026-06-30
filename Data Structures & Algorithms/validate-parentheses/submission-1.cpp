class Solution {
public:
    bool isValid(string s) {
        vector<char> carr;
        for(char c : s){
            if(c == '(' or c == '{' or c == '['){
                carr.push_back(c);
            }
            else if(c == ')'){
                if(!carr.empty()){
                    char top = carr.back();
                    carr.pop_back();
                    if(top != '('){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(!carr.empty()){
                    char top = carr.back();
                    carr.pop_back();
                    if(top != '{'){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if(c == ']'){
                if(!carr.empty()){
                    char top = carr.back();
                    carr.pop_back();
                    if(top != '['){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!carr.empty()){
            return false;
        }
        return true;
    }
};
