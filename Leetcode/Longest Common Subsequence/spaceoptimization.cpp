class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<int> prev(n+1, 0);
        
        for(int i=m-1 ;  i>=0 ; i--){
            vector<int> curr(n+1, 0);
            for(int j=n-1 ; j>=0 ; j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], prev[j]);
                }
            }
            
            prev = curr;
        }
        
        return prev[0];
    }
};
