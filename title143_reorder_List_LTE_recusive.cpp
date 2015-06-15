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
    void recusive( ListNode * head, int N)
    {
        if(N==0)
        {
            head->next = NULL;
            return;
        }
        if(N==1)
        {
            head->next->next = NULL;
            return;
        }
        ListNode *head2 = head->next;
        ListNode *cur = head;
        for( int i=0; i<N; ++i)
        {
            cur = cur->next;
        }
        
        head->next = cur;
        cur->next = head2;
        recusive( head2, N-2);
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *cur = head;
        int len = 0;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        recusive( head, len-1);
    }
};