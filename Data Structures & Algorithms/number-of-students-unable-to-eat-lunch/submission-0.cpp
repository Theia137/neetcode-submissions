class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> q_students;
        deque<int> q_sandwiches;
        int num = 0;
        for(int stu : students){
            q_students.push_back(stu);
        }
        for(int sand : sandwiches){
            q_sandwiches.push_back(sand);
        }
        while(!q_sandwiches.empty()){
            int topstu = q_students.front();
            int topsand = q_sandwiches.front();
            if(topstu == topsand){
                q_sandwiches.pop_front();
                q_students.pop_front();
                num = 0;
            }
            else{
                num += 1;
                q_students.pop_front();
                q_students.push_back(topstu);
                if(num == q_students.size()){
                    break;
                }
            }
        }
        return q_students.size();
    }
};