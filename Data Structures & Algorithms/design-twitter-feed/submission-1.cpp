class Twitter {
public:
    priority_queue<pair<int,int>>maxHeap;
    int c;
    vector<tuple<int,int,int>>x;
    map<int,unordered_set<int>>flw;
    Twitter() {
        c=0;
    }
    
    void postTweet(int userId, int tweetId) {
        c++;
        x.push_back({c,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId){
        unordered_set<int>flws;
        flws.insert(userId);
        for(auto i:flw[userId]){
            flws.insert(i);
        }
        vector<int>ans;
        sort(x.rbegin(),x.rend());
        for(int i=0;i<x.size()&&ans.size()<10;i++){
            auto [time, tweetId, author] = x[i];
            if(flws.contains(author)){
                ans.push_back(tweetId);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for(auto i:flw[followerId]){
            if(i==followeeId){
                flw[followerId].erase(i);
                break;
            }
        }
    }
};
