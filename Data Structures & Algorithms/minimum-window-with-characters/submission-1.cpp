class Solution {
public:
    string minWindow(string s, string t1) {
        unordered_map<char,int>u,t;
        for(auto i:t1) u[i]++;
        int mn=INT_MAX,start=0,l=0,r=0;
        int reqd=u.size(),formed=0;
        while(r<s.size()){
            char c=s[r];
            t[c]++;
            if(u.count(c)&&t[c]==u[c])
                formed++;
            while(l<=r && formed==reqd){
                if(r-l+1<mn){
                    mn=r-l+1;
                    start=l;
                }
                char x=s[l];
                t[x]--;
                if(u.count(x) && t[x]<u[x]) formed--;

                l++;
            }
            r++;
        }
        return mn==INT_MAX?"":s.substr(start,mn);
    }
};
