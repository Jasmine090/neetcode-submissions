class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size();i++)pq.push(stones[i]);
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            x -= pq.top();
            pq.pop();
            if(abs(x)) pq.push(abs(x));
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
