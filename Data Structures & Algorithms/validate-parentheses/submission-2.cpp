class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(auto i :s){
            if(i=='('||i=='{'||i=='['){
                a.push(i);
            }else{
                if(a.empty()) return false;
                if(i==')'){
                    if(a.top()!='(') return false;
                    a.pop();
                }else if(i=='}'){
                    if(a.top()!='{') return false;
                    a.pop();
                }else if(i==']'){
                    if(a.top()!='[') return false;
                    a.pop();
                }
            }
        }
        if(a.empty()) return true;
        return false;
    }
};
