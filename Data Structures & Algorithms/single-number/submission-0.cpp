class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1])
                     return nums[i];
            }else if(i==n-1){
                if(nums[i]!=nums[i-1])
                     return nums[i];
            }
            else if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
    }
};
