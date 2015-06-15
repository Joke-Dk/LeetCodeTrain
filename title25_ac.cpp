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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( k==1) return head;
        ListNode *ret = new ListNode (0);
        ret->next = head;
        ListNode *begin = ret;
        //k--;
        while(1)
        {
            bool stop = 0;
            ListNode *cur = begin->next;
            for( int i=0; i<k; ++i)
            {
                if(cur)
                {
                    cur = cur->next;
                }
                else
                {
                    stop = 1;
                    break;
                }
            }
            if(stop) break;
            //else
            cur = begin->next;
            ListNode *pre = NULL;
            ListNode *next;
            for( int i=0; i<k; ++i)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            
            //update begin
            cur = begin->next;
            begin->next = pre;
            begin = cur;
            begin->next = next;
        }
        return ret->next;
        
    }
};