class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,vector<int>,greater<int>>v;
        vector<int>hash(2001);
        for(auto i : nums)
        {
            hash[i+1000]++;
        }
        int j=0;
        vector<int>sorted;
        for(int i=2000;i>=0;i--)
        {
            if(hash[i]!=0){
                v[hash[i]].emplace_back(i-1000);
            }
        }
        for(auto i:v){
            if(j>=k) break;
            cout<<i.second[0]<<" ";
            for(auto q:i.second){
                if(j>=k) break;
                sorted.emplace_back(q);
                j++;
            }
        }
        
        return sorted;
    }
};
