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
    
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode * cur1 = head, *cur2 = head, *pre0 = NULL;
        while(cur2->next && cur2->next->next)
        {
            pre0 = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next->next;
        }
        
        ListNode* mid = cur1->next;
        cur1->next = NULL;
        //reverse the last half list
        ListNode *pre = NULL;
        while( mid)
        {
            ListNode *last = mid->next;
            mid->next = pre;
            pre = mid;
            mid = last;
        }
        
        //Now mid=end List
        ListNode *end = pre;
        ListNode *cur = head;
        while(end)
        {
            ListNode* rev = end->next;
            ListNode* head1 = cur->next;
            cur->next = end;
            end->next = head1;
            end = rev;
            cur = head1;
        }
    }
};