class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v(nums.size());
        vector<int>p(nums.size());
        vector<int>s(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=p[i-1]*nums[i];
        }
        s[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            s[i]=s[i+1]*nums[i];
        }
        for(int i=1;i<nums.size()-1;i++){
            v[i]=p[i-1]*s[i+1];
        }
        v[nums.size()-1]=p[nums.size()-2];
        v[0]=s[1];
        return v;
    }
};
