class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        backtrack(s,ans,0,res);
        return ans;
    }

    void backtrack(string &s, vector<vector<string>>& ans, int i, vector<string>&res){
        if(i==s.size()){
            ans.push_back(res);
        }
        for(int j=i;j<s.size();j++){
            if(palCheck(s,i,j)){
                res.push_back(s.substr(i,j-i+1));
                backtrack(s,ans,j+1,res);
                res.pop_back();
            }
        }
    }
    bool palCheck(string & s,int i,int r){
        if(i>r) return true;
        if(s[i]!=s[r]) return false;
        return palCheck(s,i+1,r-1);
    }
};