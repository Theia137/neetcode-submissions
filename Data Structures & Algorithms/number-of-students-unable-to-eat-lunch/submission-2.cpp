class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q_students;
        for(int stu : students){
            q_students.push(stu);
        }

        int res = sandwiches.size();
        for(int sand : sandwiches){
            int cnt = 0;
            while(q_students.front() != sand && cnt != res)
            {
                q_students.push(q_students.front());
                q_students.pop();
                cnt += 1;
            }
            if(q_students.front() == sand){
                q_students.pop();
                res -= 1;
                cnt = 0;
            }
            if(cnt == res){
                break;
            }
        }
        return res;
    }
};