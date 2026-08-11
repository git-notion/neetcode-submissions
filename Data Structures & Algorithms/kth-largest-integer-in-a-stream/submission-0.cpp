class KthLargest {
public:
vector<int> num;
int p;
    KthLargest(int k, vector<int>& nums) {
        num.push_back(0); // dummy at index 0
        num.insert(num.end(), nums.begin(), nums.end());
        p=k;
        while(num.size()>k+1){
            for(int i=num.size()/2;i>0;i--){
                heapify(num,i);
            }
            swap(num[1],num[num.size()-1]);
            num.pop_back();
        }
        for(int i=num.size()/2;i>0;i--){
                heapify(num,i);
        }

    }
    
    int add(int val) {
        num.emplace_back(val);
        while(num.size()>p+1){
            for(int i=num.size()/2;i>0;i--){
                heapify(num,i);
            }
            swap(num[1],num[num.size()-1]);
            num.pop_back();
        }
        for(int i=num.size()/2;i>0;i--){
                heapify(num,i);
        }
        return num[1];
    }
private:
    void heapify(vector<int>& nums,int i){
        int l=2*i,r=2*i+1,largest;
        if(l<=nums.size()-1&&nums[l]<nums[i])   largest=l;
        else largest=i;
        if(r<=nums.size()-1&&nums[r]<nums[largest])   largest=r;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,largest);
        }
    }
};
