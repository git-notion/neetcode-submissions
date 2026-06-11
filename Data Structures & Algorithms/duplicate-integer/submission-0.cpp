class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>v;
        for(auto i:nums){
            if (v.find(i) != v.end()) {
                return true;
            }v.insert(i);
        }return false;
    }
};