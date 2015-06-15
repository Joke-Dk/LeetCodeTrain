/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = new ListNode(0);
        ListNode *cur = ret;
        while( head&&head->next)
        {
            cur->next = new ListNode(head->next->val);
            cur->next->next = new ListNode(head->val);
            cur = cur->next->next;
            head = head->next->next;
        }
        if(head)
        {
            cur->next = head;
        }
        return ret->next;
    }
};