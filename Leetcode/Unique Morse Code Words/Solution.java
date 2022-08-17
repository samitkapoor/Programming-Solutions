class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morseEquivalent = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        Map<String, Integer> morseCodes = new HashMap<String, Integer>();
        
        for(int i=0 ; i<words.length ; i++){
            String wordInMorse = "";
            
            for(int j=0 ; j<words[i].length() ; j++){
                wordInMorse += morseEquivalent[(int)words[i].charAt(j) - (int)'a'];
            }
            
            if(!morseCodes.containsValue(wordInMorse)){
                morseCodes.put(wordInMorse, 1);
            }
        }
        
        return morseCodes.size();
    }
}
