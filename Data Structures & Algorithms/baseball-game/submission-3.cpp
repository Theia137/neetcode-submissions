class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> oper;
        for(int i=0; i<n; i++){
            string s = operations[i];
            if(s.length() == 1){
                char c = s[0];
                if(c == '+'){
                    int a = oper.back();
                    oper.pop_back();
                    int b = oper.back();
                    oper.pop_back();
                    int ab = a + b;
                    oper.push_back(b);
                    oper.push_back(a);
                    oper.push_back(ab);
                }
                else if(c == 'C'){
                    oper.pop_back();
                }
                else if(c == 'D'){
                    int top = oper.back();
                    oper.push_back(top * 2);
                }
                else{
                    int num = c-48;
                    oper.push_back(num);
                }
            }
            else{
                if(s[0] == '-'){ 
                    int sum = 0;
                    for(int i = 1; i<s.length(); i++){
                        int num = s[i]-48;
                        sum += num * pow(10, s.length()-i-1);
                    }
                    oper.push_back(-1 * sum);
                }
                else{
                    int sum = 0;
                    for(int i = 0; i<s.length(); i++){
                        int num = s[i]-48;
                        sum += num * pow(10, s.length()-i-1);
                    }
                    oper.push_back(sum);
                }
            }
        }
        int sum = 0;
        for(int num : oper){
            sum += num;
        }
        return sum;
    }
};