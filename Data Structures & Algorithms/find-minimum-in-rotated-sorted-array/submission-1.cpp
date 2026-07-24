class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans=nums[0],n=nums.size();
        int l=0,r=n-1;
        int m;
        while(l<=r){
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            m=(l+r)/2;
            ans=min(ans,nums[m]);
            if(nums[m]>=nums[l]) l=m+1;
            else r=m-1;
        }
        return ans;
    }
};
