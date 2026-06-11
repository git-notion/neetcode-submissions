class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        int n=nums.size();
        int c=0;
        for(auto i:nums){
            if(i==0)c++;
        }
        if(c==n){
            return{{0,0,0}};
        }
        for(int i=0;i<n-1;i++){
            cout<<"hi ";
            int l=i+1,r=n-1;
            int target=-1*nums[i];
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    vector<int>a={nums[i],nums[l],nums[r]};
                    v.emplace_back(a);l++;r--;
                }
                else if(sum>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                v.erase(v.begin()+i);
                i--;
            }
        }
        return v;
    }
};
