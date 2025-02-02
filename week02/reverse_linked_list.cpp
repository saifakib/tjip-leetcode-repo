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
       auto curr = head;
       ListNode* prev = nullptr;

       while(curr) {
           auto next = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = next;
       }
       return prev;
    }
};