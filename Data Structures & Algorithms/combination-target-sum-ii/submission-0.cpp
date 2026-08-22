class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,0,target,candidates,ans,curr);
        return ans;
    }
    void helper(int i,int sum,int target, vector<int>& nums,vector<vector<int>>&ans, vector<int>&curr)
    {
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target){
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])    continue;
            curr.push_back(nums[j]);
            helper(j+1,sum+nums[j],target,nums,ans,curr);
            curr.pop_back();
        }
    }
};