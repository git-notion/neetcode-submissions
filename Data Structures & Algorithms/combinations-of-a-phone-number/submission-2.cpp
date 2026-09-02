class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<vector<char>>comb;
        vector<string>ans;
        string curr="";
        for(auto i: digits){
            vector<char>v;
            if(i=='7'){
                comb.push_back({'p','q','r','s'});
            }
            else if(i=='9'){
                comb.push_back({'w','x','y','z'});
            }
            else if(i=='8'){
                comb.push_back({'t','u','v'});
            }
            else{
                int z=i-'0';
                v={
                    static_cast<char>('a'+(z-2)*3),
                    static_cast<char>('a'+(z-2)*3+1),
                    static_cast<char>('a'+(z-2)*3+2)};
                comb.push_back(v);
            }
        }
        cout<<comb.size();
        backtrack(comb,ans,curr,0);
        return ans;
    }
    void backtrack(vector<vector<char>>& comb, vector<string>& ans, string curr, int i){
        if(i==comb.size()){
            ans.push_back(curr);
            return;
        }
        for(char c:comb[i]){
            curr.push_back(c);
            backtrack(comb,ans,curr,i+1);
            curr.pop_back();
        }
    }
};
