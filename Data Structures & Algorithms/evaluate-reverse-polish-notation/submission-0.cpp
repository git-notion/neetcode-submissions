class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (auto& w : tokens) {
            if (w == "+" || w == "-" || w == "*" || w == "/") {
                int a = s.top(); s.pop(); 
                int b = s.top(); s.pop(); 

                int result = 0;
                if      (w == "+") result = b + a;
                else if (w == "-") result = b - a; 
                else if (w == "*") result = b * a;
                else if (w == "/") result = b / a;  

                s.push(result);  
            } else {
                s.push(stoi(w));  
            }
        }

        return s.top();  
    }
};
