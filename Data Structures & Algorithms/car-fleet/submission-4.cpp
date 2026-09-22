class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        stack<pair<int, int>> st;
        st.push(v[0]);
        for(int i=1;i<v.size();i++){
            //cout << v[i].first << endl;
            double time1 = 
            (double)(target-st.top().first)/st.top().second;
            double time2 = (double)(target-v[i].first)/v[i].second;
            //cout << time1 << ' ' << time2 << endl;
            if(time1 < time2){
                st.push(v[i]);
            }
            
        }
        return st.size();
    }
};
