class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if((int)matchsticks.size() < 4){
            return false;
        }
        
        int perimeter = 0;
        
        for(int i=0 ; i<(int)matchsticks.size() ; i++){
            perimeter += matchsticks[i];
        }
        
        if(perimeter % 4 != 0){
            return false;
        }
        
        int side = perimeter/4;
        vector<int> sides(4, side);
        
        sort(matchsticks.begin(), matchsticks.end(), [](int a, int b){
            return a > b;
        });
        
        return squareMaker(matchsticks, 0, sides);
    }
    
    bool squareMaker(vector<int>& matchsticks, int i, vector<int>& sides){
        if(i == (int)matchsticks.size()){
            return (sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0);
        }
        
        for(int j=0 ; j<4 ; j++){
            if(matchsticks[i] > sides[j]){
                continue;
            }
            
            sides[j] -= matchsticks[i];
            
            if(squareMaker(matchsticks, i+1, sides)){
                return true;
            }
            
            sides[j] += matchsticks[i];
        }
        
        return false;
    }
    
};
