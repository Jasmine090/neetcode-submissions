class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //priority_queue<int> pq;
        //for(int& s:stones)pq.push(s);
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            x -= pq.top();
            pq.pop();
            if(x) pq.push(x);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
