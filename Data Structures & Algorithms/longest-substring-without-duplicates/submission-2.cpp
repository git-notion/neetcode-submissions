class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.size(),r=0;
        unordered_map<int,int>u;
        int sz=INT_MIN;
        if(s.empty()){
            return 0;
        }
        while(l<=r&&r<n)
        {
            u[s[r]]++;
            while(u[s[r]]>1){
                sz=max(sz,r-l);
                u[s[l]]--;
                l++;
            }
            //sz=max(sz,r-l);
            r++;
        }
        sz=max(sz,r-l);

        return sz;
    }
};
