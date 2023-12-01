/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// TC: 0(1)
// SC: 0(1)
class Solution {
public:

    void deleteNode(ListNode* node) {
        auto remove_node = node -> next;
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
        delete(remove_node);
    }
};