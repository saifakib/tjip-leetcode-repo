// TC: 0(1)
// MC: 0(capacity)
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(k_val.count(key) == 0) return  -1;
        // event should be fast
        updateLRU(key);
        return k_val[key];
    }
    
    void put(int key, int value) {
        if(k_val.count(key) == 0 && lru.size() == cap) {
            // remove most low frequency events
            evict();
        }
        updateLRU(key);
        k_val[key] = value;
    }
private: 
    int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> k_loc;
    unordered_map<int, int> k_val;

    void updateLRU(int &key) {
        if(k_val.count(key) > 0) {
            lru.erase(k_loc[key]);
        }
        lru.push_front(key);
        k_loc[key] = lru.begin();
    }

    void evict() {
        k_loc.erase(lru.back());
        k_val.erase(lru.back());
        lru.pop_back();
    }
};
