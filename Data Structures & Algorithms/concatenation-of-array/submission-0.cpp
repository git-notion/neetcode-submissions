class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v(2*nums.size());
        int n=nums.size();
        int j=0;
        for(auto &i:v){
            if(j<n) i=nums[j];
            else i=nums[j-n];
            j++;
        }return v;
    }
};