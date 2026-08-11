class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(),stones.end());
        while(stones.size()>1){
            int x=stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            int u=stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            if(x!=u){
                stones.push_back(abs(u-x));
                pop_heap(stones.begin(),stones.end());
            }
        }
        if(stones.size()==0){
            return 0;
        }else return stones[0];
    }
};
