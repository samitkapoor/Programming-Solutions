import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        Arrays.sort(nums);
        
        for(int i=0 ; i<nums.length - 1; i++){
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                int l = i+1;
                int r = nums.length-1;
                while(l < r){
                    int temp = nums[i] + nums[l] + nums[r];
                    if(temp == 0){
                        result.add(Arrays.asList(nums[i], nums[l], nums[r]));
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(temp > 0) r--;
                    else l++;
                }
            }
        }
                                
        return result;
    }
}