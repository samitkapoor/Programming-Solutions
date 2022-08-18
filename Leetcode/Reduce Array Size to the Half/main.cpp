class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        
        for(auto i : arr){
            m[i]++;
        }
        
        multimap<int, int, greater<int>> mm;
        
        for(auto p : m){
            mm.insert({p.second, p.first});
        }
        
        int n = arr.size();
        int sum = n;
        int count = 0;
        for(auto it = mm.begin() ; it != mm.end() ; it++){
            sum -= it->first;
            count++;
            
            if(sum <= n/2){
                break;
            }
        }
        
        return count;
    }
};
