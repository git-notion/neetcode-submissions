class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>a;
        if(nums.empty()) return 0;
        for(auto i:nums){
            a[i]++;
        }

        int n=a.size(),maz=0,a1=1,x;
        bool ini=false;
        for(auto i:a){
            
            if(!ini){
                x=i.first;
                ini=true;
                continue;
            }
            else if(x==i.first-1){
                a1++;
                cout<<"h1";
                maz=max(maz,a1);
            }else{
                cout<<i.first;
                a1=1;
            }
            x=i.first;
        }
        maz=max(maz,a1);
        return maz;
    }
};
