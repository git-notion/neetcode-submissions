class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>checked(nums.size(),false);
        helper(nums,ans,curr,checked);
        return ans;
    }
    void helper(vector<int>& nums,vector<vector<int>>&ans, vector<int>&curr,vector<bool>&checked){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int j=0;j<nums.size();j++){
            if(!checked[j]){
                checked[j]=true;
                curr.push_back(nums[j]);
                helper(nums,ans,curr,checked);
                checked[j]=false;
                curr.pop_back();
            }
        }
    }
};
