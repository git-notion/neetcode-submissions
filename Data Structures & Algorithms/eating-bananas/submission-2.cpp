class Solution {
public:
    long long minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long mx=*max_element(piles.begin(),piles.end());
        long long mn=1;
        long long mid=(mn+mx)/2;
        long long ans=mx;
        while(mn<=mx){
            mid=(mn+mx)/2;
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=(piles[i]+mid-1)/mid;

            }if(sum<=h){
                ans=mid;
                mx=mid-1;
            }else{
                mn=mid+1;
            }
        }
        return ans;
    }
};
