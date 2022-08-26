class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] countN = digitsCounter(n);
        
        int x = 1;
        
        for(int i = 0 ; i < 31 ; i++){
            if(Arrays.equals(countN, digitsCounter(x))) return true;
            
            x=x<<1;
        }
        
        return false;        
    }
    
    public int[] digitsCounter(int n){
        int[] arr = new int[10];
        
        while (n != 0) {
            arr[n%10]++;
            n/=10;
        }
        
        return arr;
    }
}
