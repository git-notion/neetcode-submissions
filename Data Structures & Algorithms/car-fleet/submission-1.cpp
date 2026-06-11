class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v(speed.size());
        int i=0, fleet=01;
        for (auto& i1 : v) {
            i1.first = position[i];
            i1.second = speed[i];
            i++;
        }
        sort(v.rbegin(),v.rend());
        stack <float>tm;
        for (auto& i : v) {
            float time=(float)(target-i.first)/i.second;
            if(tm.empty())
            {
                tm.push(time);
            }
            else
            {
                if(time<=tm.top())
                {
                    //tm.pop();
                }
                else
                {
                    fleet++;
                    tm.push(time);
                }
            }
            cout<<time<<" ";
        }
        return fleet;
    }
};
