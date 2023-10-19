/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// TC: 0(N)
// SC: 0(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* cHead;
       ListNode* prev = NULL;

       while(head != NULL) {
           cHead = head;
           head = head -> next;
           cHead -> next = prev;
           prev = cHead;
       }

       return prev;

    }
};