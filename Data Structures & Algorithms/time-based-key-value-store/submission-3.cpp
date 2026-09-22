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
        auto& a = mp[key];
        int right = a.size()-1;
        int mid;
        string re = "";
        while(left <= right){
            mid = (left+right)/2;
            if(a[mid].first<=timestamp){
                re = a[mid].second;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return re;
    }
};
