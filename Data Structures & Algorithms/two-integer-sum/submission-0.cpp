class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int second = target - nums[i];
            auto found = hash.find(second);
            if(found != hash.end()) {
                result.push_back(found->second);
                result.push_back(i);
                return result;
            } else {
                hash[nums[i]] = i;
            }
        }
        return result;
    }
};
