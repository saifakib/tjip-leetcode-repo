// TC: 0(1) // On average
// SC: 0(128 * S) // S number of key
class MyHashMap {
    private:
    class Node {
        public:
        int key, value;
        Node* next;
        Node(int k, int v, Node* _next) {
            key = k;
            value = v;
            next = _next;
        }
    };
    int calculateHash(int key) {
        return ((key * BASE) + OFFSET) % CAPACITY;
    }
public:
    const static int CAPACITY = 128;
    const static int BASE = 257;
    const static int OFFSET = 1999;
    Node* slots[CAPACITY] = {};
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int slotID = calculateHash(key);
        auto new_node = new Node(key, value, slots[slotID]);
        // put node on the head
        slots[slotID] = new_node;
    }
    
    int get(int key) {
        int slotID = calculateHash(key);
        auto node = slots[slotID];
        while(node) {
            if(node -> key == key) return node -> value;
            node = node -> next;
        };
        return -1;
    }
    
    void remove(int key) {
        int slotID = calculateHash(key);
        if(slots[slotID] == nullptr) return;
        auto node = slots[slotID];
        // if target node(key) is head
        if(node -> key == key) {
            slots[slotID] = node -> next;
            delete node;
            return;
        };

        while(node && node -> next) {
            if(node -> next -> key == key) {
                auto temp = node -> next;
                node -> next = temp -> next;
                delete temp;
                return;
            };
            node = node -> next;
        }
    }
};