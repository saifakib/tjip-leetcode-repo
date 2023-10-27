/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// TC: 0(N)
// SC: 0(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> cache;
        auto currOriginalHead = head;

        auto dNewHead = new Node(0);
        auto cNewhead = dNewHead;

        // make a new linked list also a map where key original node and value is new node
        while(currOriginalHead) {
            auto node = new Node(currOriginalHead -> val);
            cache[currOriginalHead] = node;
            currOriginalHead = currOriginalHead -> next;
            cNewhead -> next = node;
            cNewhead = cNewhead -> next;
        };

        auto newHead = dNewHead -> next;
        currOriginalHead = head;
        // set random pointers in the new list.
        while(currOriginalHead) {
            if(currOriginalHead -> random) {
                newHead -> random = cache[currOriginalHead -> random];
            }
            currOriginalHead = currOriginalHead -> next;
            newHead = newHead -> next;
        }
        return dNewHead -> next;
    }
};