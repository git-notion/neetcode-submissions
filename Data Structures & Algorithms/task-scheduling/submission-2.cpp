class Solution {
private:
    vector<int> v = vector<int>(26, 0);
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        for(auto i:tasks){
            v[i-65]++;
        }
        priority_queue<int>maxHeap;
        for(auto i :v){
            if(i>0) maxHeap.push(i);
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!maxHeap.empty()||!q.empty())
        {
            time++;
            if(!q.empty()&&q.front().second==time){
                maxHeap.push(q.front().first);
                q.pop();
            }
            if(maxHeap.empty()) continue;

            int a=maxHeap.top();
            maxHeap.pop();
            a--;
            if(a>0){
                q.push({a,time+n+1});
            }
        }
        return time;
    }
};
