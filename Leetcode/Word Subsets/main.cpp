class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> max_char_freq(26,0);
        for(int i=0 ; i<words2.size() ; i++){
            string current_word = words2[i];
            
            vector<int> current_word_freq = get_frequencies(current_word);
            
            for(int j=0 ; j<26 ; j++){
                max_char_freq[j] = max(max_char_freq[j], current_word_freq[j]);
            }
        }
        
        for(int i=0 ; i<words1.size() ; i++){
            string current_word = words1[i];
            
            vector<int> current_word_freq = get_frequencies(current_word);
            
            bool valid = true;
            for(int j=0 ; j<26 ; j++){
                if(max_char_freq[j] > current_word_freq[j]){
                    valid = false;
                    break;
                }
            }
            
            if(valid){
                result.push_back(current_word);
            }
        }
        
        return result;
        
    }
    
    vector<int> get_frequencies(string s){
        vector<int> chars(26,0);
        
        for(char c : s){
            chars[c-'a']++;
        }
        
        return chars;
    }
};
