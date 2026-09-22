class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        if(nums.size()>k){
            int tmp = nums.size()-k;
            while(tmp--) pq.pop();
        }
        K = k;
    }
    
    int add(int val) {
        if(pq.size()<K) pq.push(val);
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
