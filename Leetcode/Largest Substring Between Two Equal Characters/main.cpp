class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> m;
        int answer = -1`;
        for(int i = 0 ; i < s.length() ; i++){
            if(m[s[i]] == 0) {
                m[s[i]] = i + 1;
            } else {
                answer = max(answer, i - m[s[i]]);
            }
        }

        return answer;
    }
};
