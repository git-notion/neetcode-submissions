class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(),j=0;
        vector<pair<int,int>>v(n);
        for(auto &i:v){
            i.first=nums[j];
            i.second=j;
            j++;
        }sort(v.begin(),v.end());
        vector<int>v1;
        bool AnswerFound=true;
        int l=0,r=n-1;
        while(AnswerFound){
            int ans=v[l].first+v[r].first;
            if(ans==target){
                v1.emplace_back(v[l].second);
                v1.emplace_back(v[r].second);
                break;
            }else if(ans>target) r--;
            else l++;
        }
        sort(v1.begin(),v1.end());
        return v1;
    }
};