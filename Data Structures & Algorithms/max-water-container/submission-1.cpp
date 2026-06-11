class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int>v;
        int a=INT_MIN;
        int l=0,n=heights.size(),r=n-1;
        while(l<r){
            if(heights[l]<heights[r]){
                a=max(a,(r-l)*min(heights[l],heights[r]));
                l++;
            }
            else if(heights[l]>heights[r]){
                a=max(a,(r-l)*min(heights[l],heights[r]));
                r--;
            }
            else{
                a=max(a,(r-l)*min(heights[l],heights[r]));
                if(l<r) l++;
                else r--;
            }

        }
        return a;
    }

};
