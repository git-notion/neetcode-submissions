class Solution {
private:
    priority_queue<pair<long long,vector<int>>>maxHeap;
    int k;
    long long dist(int x1,int y1){
        return (long long)x1*x1+(long long)y1*y1;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        this->k=k;
        for(auto& i:points){
            long long d=dist(i[0],i[1]);
            maxHeap.push({d,i});
            if(maxHeap.size()>k)    maxHeap.pop();
        }
        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
