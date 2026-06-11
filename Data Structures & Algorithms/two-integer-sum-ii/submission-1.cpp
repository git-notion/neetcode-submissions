class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,n=numbers.size(),r=n-1;
        vector<int>ans;
        while(l<r){
            int test=numbers[l]+numbers[r];
            if(test<target){
                l++;
            }
            else if(test>target){
                r--;
            }else{
                ans.emplace_back(l+1);
                ans.emplace_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};
