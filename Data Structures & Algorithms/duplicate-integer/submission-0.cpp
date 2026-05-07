#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> exists;
        for(int i = 0; i < nums.size(); i++) {
            if(exists.find(nums[i]) != exists.end())
                return true;
            exists[nums[i]] = true;
        }
        return false;
    }
};