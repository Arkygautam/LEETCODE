class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.size() == 1){
            return stones[0];
        }

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();

            if(f == s ){
                continue;
            }
            else{
                pq.push(f-s);
            }
        }

        if(pq.size() == 1){
            return pq.top();
        }

        return 0;

    }
};