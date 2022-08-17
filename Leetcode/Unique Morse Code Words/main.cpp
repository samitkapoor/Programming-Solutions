class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_equivalent{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string, int> morse_codes;
        
        for(string word : words){
            
            string morse_code = "";
            
            for(char ch : word){
                morse_code += morse_equivalent[ch-'a'];
            }
            
            morse_codes[morse_code]++;
            
        }
        
        return morse_codes.size();
    }
};
