class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequencies(26, 0);
        for(char c : s){
            frequencies[c-'a']++;
        }
        
        priority_queue<int> pq;
        for(int i=0 ; i<26 ; i++){
            if(frequencies[i] > 0) pq.push(frequencies[i]);
        }
        
        int result = 0;
        while(pq.size() > 1){
            int top = pq.top();
            pq.pop();
            
            if(top == pq.top()){
                if(top - 1 > 0){
                    pq.push(top-1);
                }
                result++;
            }
        }
        
        return result;
    }
};
