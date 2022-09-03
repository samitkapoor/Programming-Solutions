class Solution {
public:
    int count(int n){
        int count = 0;
        while(n != 0){
            n/=10;
            count++;
        }
        
        return count;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        
        vector<int> start{1,2,3,4,5,6,7,8,9};
        
        for(int i=0 ; i<9 ; i++){
            stack<int> stk;
            
            stk.push(start[i]);
            
            while(!stk.empty()){
                int t = stk.top();
                stk.pop();
                
                if(count(t) == n){
                    result.push_back(t);
                }
                else{
                    int last = t%10;
                    int pre = last - k;
                    int pos = last + k;
                    
                    int temp = t;
                    
                    if(pre >= 0 && pre < 10){
                        temp = temp * 10;
                        temp += pre;
                        stk.push(temp);
                    }
                    if(pos >= 0 && pos < 10 && pre != pos){
                        temp = t;
                        
                        temp = temp * 10;
                        temp += pos;
                        stk.push(temp);
                    }
                }
            }
        }
        
        return result;
    }
};
