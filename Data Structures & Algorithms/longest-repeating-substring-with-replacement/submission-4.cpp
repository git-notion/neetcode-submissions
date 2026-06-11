
#define fi first
#define se second
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==1) {
            return 1;
        }
        unordered_map<int,int>u;
        int l=0,left=0,mx=0;
        for(int i=0;i<s.size();i++){
            u[s[i]]++;
            mx=max(mx,u[s[i]]);
            while(i-left-mx+1>k){
                u[s[left]]--;
                left++;

            }
            l=max(l,i-left+1);
            
        }
        return l;
    }
};
