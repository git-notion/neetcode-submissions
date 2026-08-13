class Solution {
private:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int k;
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k=k;
        for(int i:nums){
            minHeap.push(i);
            if(minHeap.size()>k)    minHeap.pop();
        }
        return minHeap.top();
    }
};
