class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>v;
        int mn=INT_MAX;
        for(auto i:prices)
        {
            mn=min(mn,i);
            v.emplace_back(mn);
        }
        int profit=INT_MIN;
        for(int i=0;i<v.size();i++){
            profit=max(profit,prices[i]-v[i]);
        }
        return profit;
    }
};
