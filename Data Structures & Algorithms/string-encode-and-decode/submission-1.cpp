class Solution {
public:

    string encode(vector<string> &strs)
{
    if(strs.empty()){return "";}
    string s = "";
    s += to_string(strs.size());
    s += "  ";

    for (auto i : strs)
    {
        s += to_string(i.size());
        s += " ";
    }
    s += "  ";
    for (auto i : strs)
    {
        s += i;
    }
    return s;
}

vector<string> decode(string s)
{
    if(s.empty()) return {};
    vector<string> v;
    string ss = "";
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            x = i;
            break;
        }
        else
        {
            ss += s[i];
        }
    }
    int n = stoi(s);
    vector<int> sizes;
    ss = "";
    for (int i = x + 2; i < s.size(); i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2] && s[i] == ' ')
        {
            sizes.emplace_back(stoi(ss));
            ss = "";
            x = i + 3;
            break;
        }
        else if (s[i] == ' ')
        {
            sizes.emplace_back(stoi(ss));
            ss = "";
            continue;
        }
        
        else
        {
            ss += s[i];
        }
    }
    
    int tt = n, i = 0;
    while (tt--)
    {
        string qq = "";
        int r=x+sizes[i];
        while (x < r)
        {
            qq.push_back(s[x]);
            x++;
        }
        v.emplace_back(qq);
        i++;
    }
    return v;
}
};
