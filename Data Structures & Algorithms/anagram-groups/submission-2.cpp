class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> org=strs;
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        vector<pair<string,string>> v(n);
        for(int i=0;i<strs.size();i++){
            v[i].first=strs[i];
            v[i].second=org[i];
        }
        sort(v.begin(),v.end());
        vector<vector<string>> res;
        vector<string> t;
        t.emplace_back(v[0].second);
        for(int i=1;i<strs.size();i++){
            if(v[i].first==v[i-1].first){
                //t.emplace_back(v[i].second);
            }else{
                res.emplace_back(t);
                t.clear();
            }t.emplace_back(v[i].second);
        }
    res.emplace_back(t);
    return res;
    }

};
