class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> re;
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first < b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<points.size();i++){
            pq.push({pow(points[i][0], 2) + pow(points[i][1], 2), i});
            
            if(pq.size() > k) pq.pop();
        }
        cout << pq.size() << endl;
        while(!pq.empty()){
            //cout << pq.top().first << endl;
            re.push_back(points[pq.top().second]);
            pq.pop();
        }
        return re;
    }
};
