class Solution {
    public int[] sortedSquares(int[] nums) {
        int negs = 0;
        int poss = 0;
        int[] result = new int[nums.length];
        
        while(negs < nums.length && nums[negs] < 0) negs++;
        negs--;
        poss = negs+1;
        
        int i = 0;
        while(negs >= 0 && poss < nums.length){
            if(nums[negs] * nums[negs] < nums[poss] * nums[poss]) {
                result[i] = nums[negs]*nums[negs];
                negs--;
            }
            else{
                result[i] = nums[poss]*nums[poss];
                poss++;
            }
            
            i++;
        }
        
        while(negs >= 0){
            result[i] = nums[negs]*nums[negs];
            i++;
            negs--;
        }
        
        while(poss < nums.length){
            result[i] = nums[poss]*nums[poss];
            i++;
            poss++;
        }
        
        return result;
    }
}
