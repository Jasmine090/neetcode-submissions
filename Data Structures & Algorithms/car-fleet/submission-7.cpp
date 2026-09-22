class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int re = 1;
        double time1 = 
            (double)(target-v[0].first)/v[0].second;
        for(int i=1;i<v.size();i++){
            double time2 = (double)(target-v[i].first)/v[i].second;
            if(time1 < time2){
                re++;
                time1 = time2;
            }
            
        }
        return re;
    }
};
