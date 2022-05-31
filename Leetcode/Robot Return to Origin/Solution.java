class Solution {
    public boolean judgeCircle(String moves) {
        int i = 0, j = 0;
        
        for(int k=0 ; k<moves.length() ; k++){
            char c = moves.charAt(k);
            if(c == 'U') i--;
            if(c == 'D') i++;
            if(c == 'L') j--;
            if(c == 'R') j++;
        }
        
        return i==0 && j==0;
    }
}
