#define eb emplace_back
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int area=heights[0], n=heights.size();
        s.push({0,heights[0]});
        for(int i=1;i<n;i++){
            if(heights[i]>=s.top().second){
                s.push({i,heights[i]});
            }else{
                int x;
                while(!s.empty()&&s.top().second>heights[i]){
                    int ar=(i-s.top().first)*s.top().second;
                    area=max(ar,area);
                    x=s.top().first;
                    s.pop();
                }
                s.push({x,heights[i]});
            }
        }
        while(!s.empty()){
            int ar=(n-s.top().first)*s.top().second;
            area=max(ar,area);
            s.pop();
        }
        return area;
    }
};
