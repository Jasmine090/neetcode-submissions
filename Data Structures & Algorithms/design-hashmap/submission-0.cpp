class MyHashMap {
public:
    int B = 10007;
    vector<vector<pair<int, int>>> mp;
    MyHashMap():mp(B) {
        
    }
    
    void put(int key, int value) {
        for(int i=0;i<mp[key%B].size();i++){
            if(mp[key%B][i].first==key){
                mp[key%B][i].second = value;
                return;
            }
        }
        mp[key%B].push_back({key, value});
        return;
    }
    
    int get(int key) {
        for(int i=0;i<mp[key%B].size();i++){
            if(mp[key%B][i].first==key) return mp[key%B][i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<mp[key%B].size();i++){
            if(mp[key%B][i].first==key){
                mp[key%B].erase(mp[key%B].begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */