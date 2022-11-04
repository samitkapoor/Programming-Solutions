class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        
        for(char c : s){
            char h = c;
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowels += h;
            }
        }
        
        int j = vowels.length()-1;
        
        for(int i=0 ; i<s.length() ; i++){
            char c = tolower(s[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                s[i] = vowels[j--];
            }
        }
        
        return s;
    }
};
