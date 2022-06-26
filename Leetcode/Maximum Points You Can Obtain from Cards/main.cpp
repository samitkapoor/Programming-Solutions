class Solution {
public:
    
    int sum(vector<int> v, int l, int r){
        int result = 0;
        for(int i=l ; i<r ; i++){
            result += v[i];
        }
        
        return result;
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = (int)cardPoints.size();
        
        int total_sum = sum(cardPoints, 0, n);
        
        int window_size = n - k;
        
        int window_sum = sum(cardPoints, 0, window_size);
        
        int result = total_sum - window_sum;
        
        for(int i = 1 ; i<=k ; i++){
            
            window_sum -= cardPoints[i-1];
            window_sum += cardPoints[i+window_size-1];
            
            result = max(result, total_sum - window_sum);
            
        }
        
        return result;
        
        
    }
};
