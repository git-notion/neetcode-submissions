class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> a;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        a[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>v=a[key];
        int n=v.size();
        if(n==0){
            return "";
        }
        int l=0,r=n-1;
        int m=(l+r)/2;
        int mx=0;string ans="";
        while(l<=r){
            m=(l+r)/2;
            if(v[m].first==timestamp){
                return v[m].second;
            }
            else if(v[m].first<=timestamp){
                if(v[m].first>=mx){
                    mx=v[m].first;
                    ans=v[m].second;
                }
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};
