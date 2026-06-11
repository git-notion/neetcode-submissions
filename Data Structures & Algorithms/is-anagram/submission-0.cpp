class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v1(26);
        vector<int>v2(26);
        for(auto i:s){
            v1[i-97]++;
        }
        for(auto i:t){
            v2[i-97]++;
        }
        return v1==v2;
    }
};
