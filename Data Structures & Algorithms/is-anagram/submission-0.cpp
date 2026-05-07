class Solution {
public:
    unordered_map<char, int> buildFreqTable(string s) {
        unordered_map<char, int> s_map;
        for(int i = 0; i < s.length(); i++) {
            if(s_map.find(s[i]) == s_map.end()) 
                s_map[s[i]] = 1;
            else 
                s_map[s[i]]++;
        }
        return s_map;
    }
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> s_map = buildFreqTable(s);
        unordered_map<char, int> t_map = buildFreqTable(t);
        return s_map == t_map;
    }
};
