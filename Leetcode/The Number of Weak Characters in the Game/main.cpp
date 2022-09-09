class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b ){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int maxTillNow = 0;
        int result = 0;
        
        for(int i = properties.size() - 1 ; i >= 0 ; i--){
            if(properties[i][1] < maxTillNow){
                result++;
            }
            
            maxTillNow = max(maxTillNow, properties[i][1]);
        }
        
        return result;
    }
};
