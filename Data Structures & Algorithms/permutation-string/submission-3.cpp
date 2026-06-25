class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>u(s1.size());
        for(auto i :s1) u[i]++;
        unordered_map<char,int>t=u;
        if(s1.size()>s2.size())return false;
        for(int i=0;i<s2.size()-s1.size()+1;i++){
            t=u;
            //cout<<"i="<<i<<endl;
            for(int j=0;j<s1.size();j++){

                if(t[s2[i+j]]!=0){
                    t[s2[i+j]]--;
                    if(t[s2[i+j]]==0) t.erase(s2[i+j]);
                    //for(auto k:t){cout<<k.first<<" "<<k.second<<endl;}
                    //cout<<endl;
                    if(t.empty()) return true;
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};