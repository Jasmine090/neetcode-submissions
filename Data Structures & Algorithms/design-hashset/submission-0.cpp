class MyHashSet {
public:
    int B = 10007;
    vector<vector<int>> mp;
    
    MyHashSet(): mp(B) { // 初始化列表，呼叫vector自己的建構子，如果是const也可以在這裡初始化
        // 建構式，const在這裡不能初始化
    }
    
    void add(int key) {
        if(contains(key)) return;
        mp[key%B].push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<mp[key%B].size();i++){
            if(mp[key%B][i]==key) mp[key%B].erase(mp[key%B].begin()+i);
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<mp[key%B].size();i++){
            if(mp[key%B][i]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */