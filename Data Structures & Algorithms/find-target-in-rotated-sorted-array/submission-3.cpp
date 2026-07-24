class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=nums[0],n=nums.size(),res=0;
        int l=0,r=n-1;
        int m=(l+r)/2;
        int last_m=m;
        while(l<=r){
            m=(l+r)/2;
            cout<<m<<" ";
            if(nums[m]==target){
                return m;
            }
            else if(l>r){
                return -1;
            }
            if(nums[m]>=nums[l]){
                if(target>=nums[l]&&target<nums[m]){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            else if(nums[m]<nums[l]){
                if(target>nums[m]&&target<=nums[r]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            last_m=m;
        }
        return -1;
    }
};
