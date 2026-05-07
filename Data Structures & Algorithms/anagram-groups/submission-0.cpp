class Solution {
public:
    struct KeyHash
    {
        std::size_t operator()(const array<int,26>& k) const
        {
            size_t h = 0;

            for (int i : k) {
                h ^= std::hash<int>{}(i) + 0xffd1333 + (h << 6) + (h >> 2);
            }
            
            return h;
        }
    };
    array<int, 26> buildFreqArr(const string& s) {
        array<int, 26> freq = {};
        for(int i = 0; i < s.length(); i++) {
            int num = s[i] - 'a';
            freq[num]++;
        }
        return freq;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, KeyHash> hash;
        for (const string& s : strs) {
            array<int, 26> freq = buildFreqArr(s);
            auto found = hash.find(freq);
            vector<string> newVec;
            newVec.push_back(s);
            if(found == hash.end()) {
                hash[freq] = newVec;
            } else {
                hash[freq].push_back(s);
            }
        }
        vector<vector<string>> result;
        for(const auto& [key, value] : hash) {
            result.push_back(value);
        }
        return result;
    }
};
