class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        long long l=0,r=height.size()-1,res=0,lM=height[l],rM=height[r];
        
        while(l<r){
            if(lM<rM){
                l++;
                lM=max(lM,(long long)height[l]);
                res+=lM-height[l];
            }
            else{
                r--;
                rM=max(rM,(long long)height[r]);
                res+=rM-height[r];
            }
        }
        return res;
    }
};