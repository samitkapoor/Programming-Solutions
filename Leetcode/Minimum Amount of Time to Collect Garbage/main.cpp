class Solution {
public:
    int find(string a, char b) {
       for(int i = 0 ; i < a.size() ; i++){
           if(a[i] == b) return i;
       }
       
       return -1;
    }
    
    string remove(string a, int i) {
        return a.substr(0, i) + a.substr(i+1);
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<char> trucks{'P', 'G', 'M'};
        int time = 0;
        
        for(int i = 0 ; i < 3 ; i++) {
            char curr = trucks[i];
            int travelTime = 0;
            
            for(int j = 0 ; j < garbage.size() ; j++) {
                if(j == 0) travelTime = 0;
                else travelTime += travel[j-1];
                
                int ind = find(garbage[j], curr);
                while(ind != -1) {
                    time += travelTime;
                    travelTime = 0;
                    garbage[j] = remove(garbage[j], ind);
                    time += 1;
                    
                    ind = find(garbage[j], curr);
                }
            }
        }
        
        return time;
    }
};
