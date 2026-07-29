class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(),m=nums1.size();
        vector<int>a,b;
        if(n>m){
            a=nums1;
            b=nums2;
        }else{
            a=nums2;
            b=nums1;
        }
        int l=0,r=a.size();
        int l1,l2,r1,r2;
        while(l<=r){
            int mid1=(l+r)/2;
            int mid2=(m+n+1)/2-mid1;
            r1=(mid1==a.size())?INT_MAX:a[mid1];
            r2=(mid2==b.size())?INT_MAX:b[mid2];
            l1=(mid1==0)?INT_MIN:a[mid1-1];
            l2=(mid2==0)?INT_MIN:b[mid2-1];
            if(l1<=r2&&l2<=r1){
                if((m+n)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                r=mid1-1;
            }
            else{
                l=mid1+1;
            }
        }
        if(l1==INT_MIN)l1=r1;
        if(l2==INT_MIN)l2=r2;
        double x=(double) (l1+r2)/2,y=(l2+r1)/2;
        cout<<l1<<" "<<l2<<"     "<<r1<<"  "<<r1<<"\n";
        return min(x,y);
    }
};
