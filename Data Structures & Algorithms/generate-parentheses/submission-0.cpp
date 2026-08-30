class Solution {
public:
    vector<string>ans;
    string curr;
    int n;
    vector<string> generateParenthesis(int n) {
        curr="";
        this->n=n;
        helper(0,0);
        return ans;
    }

    void helper(int op,int cl){
        cout<<n<<" ";
        if(cl==n && op==n){
            ans.push_back(curr);
            return;
        }
        if(op<n){
            curr+='(';
            helper(op+1,cl);
            curr.pop_back();    
        }
        if(cl<op){
            curr+=')';
            helper(op,cl+1);
            curr.pop_back();    
        }
        
    }
};