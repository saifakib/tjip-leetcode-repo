// TC: 0(N)
// SC: 0(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // create a dummy head
        auto dHead = new ListNode(0, head);
        // copy dummy head
        auto cDhead = dHead;
        auto fast = dHead;
        auto slow = dHead;

        while(n--) {
            fast = fast -> next;
        }

        while(fast && fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        auto remove_node = slow -> next;
        slow -> next = slow -> next -> next;
        delete(remove_node);

        // return dummy head next
        return cDhead -> next;
    }
};