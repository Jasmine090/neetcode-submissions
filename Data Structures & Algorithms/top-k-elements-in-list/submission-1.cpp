class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct cmp{
            bool operator()(pair<int, int>& a, pair<int, int>& b){
                return a.second > b.second;
            } 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();i++){
            if(count.count(nums[i])) count[nums[i]]++;
            else count[nums[i]] = 1;
        }
        for(const auto &a: count){
            pair<int, int> tmp(a.first, a.second);
            pq.push(tmp);
            if(pq.size()>k) pq.pop();
        }
        vector<int> re;
        while(!pq.empty()){
            re.push_back(pq.top().first);
            pq.pop();
        }
        return re;
    }
};
