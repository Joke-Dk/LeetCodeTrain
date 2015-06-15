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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur = new ListNode(0);
        ListNode *head = cur;
        while( l1&&l2)
        {
            if(l1->val>l2->val)
            {
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
            }
            else
            {
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1 = l1->next;
            }
        } 
        if(l1)
        {
            cur->next = l1;
        }
        if(l2)
        {
            cur->next = l2;
        }
        return head->next;
    }
};