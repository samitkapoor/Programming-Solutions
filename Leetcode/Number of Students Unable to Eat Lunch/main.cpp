class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circles = 0, squares = 0;

        for(int i = 0 ; i < students.size() ; i++) {
            if(students[i] == 1) squares++;
            else circles++;
        }

        for(int i = 0 ; i < sandwiches.size() ; i++) {
            if((sandwiches[i] == 0 && circles == 0) || (sandwiches[i] == 1 && squares == 0)) {
                return sandwiches.size() - i;
            } else {
                if(sandwiches[i] == 0) circles--;
                else squares--;
            }
        }

        return 0;
    }
};
