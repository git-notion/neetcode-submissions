class Twitter {
public:
    priority_queue<pair<int,int>>maxHeap;
    int c;
    unordered_map<int,vector<pair<int,int>>>x;
    map<int,unordered_set<int>>flw;
    Twitter() {
        c=0;
    }
    
    void postTweet(int userId, int tweetId) {
        c++;
        x[userId].push_back({c,tweetId});
        if(x[userId].size()>10){
            x[userId].erase(x[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId){
        unordered_set<int> users;
        users.insert(userId);

        for (auto u : flw[userId]) {
            users.insert(u);
        }
        priority_queue<tuple<int,int,int>>pq;
        for(auto i:users){
            if(!x[i].empty()){
                int idx=x[i].size()-1;
                pq.push({x[i][idx].first,i,idx});
            }
        }

        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            auto [time,user,idx]=pq.top();
            pq.pop();
            ans.push_back(x[user][idx].second);

            idx--;
            if(idx>=0){
                pq.push({x[user][idx].first,user,idx});

            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId].erase(followeeId);
    }
};
