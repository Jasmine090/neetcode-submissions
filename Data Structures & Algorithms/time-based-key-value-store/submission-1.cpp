class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        int left = 0;
        int right = mp[key].size()-1;
        int mid;
        string re = "";
        while(left <= right){
            mid = (left+right)/2;
            if(mp[key][mid].first<=timestamp){
                re = mp[key][mid].second;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return re;
    }
};
