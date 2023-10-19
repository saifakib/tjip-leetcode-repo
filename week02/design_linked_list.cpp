// TC: O(N)
// SC: 0(1)
class MyLinkedList {
  public:
    class ListNode {
      public:
        const static int DUMMY_VALUE = 0;
        int val;
        ListNode* next;
        ListNode(int _val = DUMMY_VALUE) {
          val = _val;
          next = nullptr;
        }
        ListNode(int _val, ListNode* _next) {
          val = _val;
          next = _next;
        }
    };

    int len;
    ListNode* dHead;

    MyLinkedList() {
      len = 0;
      dHead = new ListNode();
    }
    
    int get(int index) {
        if(index < 0 || index >= len) return -1;
        ListNode* cHead = dHead -> next;
        while(index--) {
          cHead = cHead -> next;
        };
        return cHead -> val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > len) return;
        ListNode* cHead = dHead;
        while(index--) {
          cHead = cHead -> next;
        }
        ListNode* newNode = new ListNode(val, cHead -> next);
        cHead -> next = newNode;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len) return;
        ListNode* cHead = dHead;
        while(index--) {
          cHead = cHead -> next;
        }
        ListNode* delete_node = cHead -> next;
        cHead -> next = cHead -> next -> next;
        delete(delete_node);
        len--;
    }
};
