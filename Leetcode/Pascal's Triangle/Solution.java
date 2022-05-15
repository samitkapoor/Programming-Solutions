import java.util.*;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        
        if(numRows == 0) return result;
        
        result.add(Arrays.asList(1));
        
        if(numRows == 1) return result;
        
        for(int i = 1 ; i<numRows ; i++){
            List<Integer> temp = new ArrayList<>();
            temp.add(1);
            for(int j=0 ; j<result.get(i-1).size() - 1 ; j++){
                temp.add(result.get(i-1).get(j) + result.get(i-1).get(j+1));
            }
            temp.add(1);
            result.add(temp);
        }
        
        return result;
    }
}