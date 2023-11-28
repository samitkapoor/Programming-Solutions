class Solution {
public:
    int numberOfWays(string corridor) {
        int flag = 0;
        long int solution = 1;
        int temp = 0;
        bool start = false;
        for(int i = 0 ; i < corridor.length() ; i++){
            if(corridor[i] == 'P' && !start) continue;
            if(corridor[i] == 'S') {
                start = true;
                
                if(flag == 0 && temp != 0) {
                    solution = (solution * (temp+1)) % (int)(1e9+7);
                    temp = 0;
                }
                
                flag = flag == 1? 0: 1;
            } else {
                if(flag == 0) temp++;
            }
        }
        
        if(flag == 1 || start == false) return 0;
        
        return (int)solution;
    }
};
