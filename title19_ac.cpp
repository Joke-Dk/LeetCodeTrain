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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int len = 0;
        while( cur)
        {
            len++;
            cur = cur->next;
        }
        cur = head;
        ListNode* pre = NULL;
        while(len>n)
        {
            len--;
            pre = cur;
            cur = cur->next;
        }
        if( pre)
        {
            pre->next = cur->next;
        }
        else
        {
            return head->next;
        }

        return head;
    }
};