class LRUCache {
    struct Node{
        Node* prev;
        Node* next;
        int key;
        int val;
    };
public:
    unordered_map<int, Node*> mp;
    Node* head = new Node{nullptr, nullptr, -1, 0};
    Node* tail = new Node{nullptr, nullptr, -1, 0};
    int c;
    int s;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        c = capacity;
        s = 0;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        mp[key]->prev->next = mp[key]->next;
        mp[key]->next->prev = mp[key]->prev;
        mp[key]->next = head->next;
        mp[key]->next->prev = mp[key];
        mp[key]->prev = head;
        head->next = mp[key];
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            mp[key]->val = value;
            mp[key]->prev->next = mp[key]->next;
            mp[key]->next->prev = mp[key]->prev;
            mp[key]->next = head->next;
            mp[key]->next->prev = mp[key];
            mp[key]->prev = head;
            head->next = mp[key];
            return;
        }
        if(s==c){
            mp.erase(tail->prev->key);
            tail->prev->prev->next = tail;
            tail->prev->next = nullptr;
            tail->prev = tail->prev->prev;
            s--;
        }
        mp[key] = new Node{head, head->next, key, value};
        head->next->prev = mp[key];
        head->next = mp[key];
        s++;
        
    }
};

