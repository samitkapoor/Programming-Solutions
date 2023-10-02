class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceTurns = 0;
        int bobTurns = 0;

        for(int i = 1 ; i < colors.length()-1 ; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A') {
                aliceTurns++;
            } else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B') {
                bobTurns++;
            }
        }

        if(aliceTurns > bobTurns) {
            return true;
        } 
        return false;
    }
};
