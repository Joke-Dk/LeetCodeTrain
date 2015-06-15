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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap< int, ListNode *> mp;
        
        for( int i=0; i<lists.size(); ++i)
        {
            if( lists[i])
            {
                //mp[ lists[i]->val] = lists[i];
                mp.insert( make_pair( lists[i]->val, lists[i]));
            }
        }
        ListNode* head= new ListNode(0);
        ListNode* cur = head;
        while( !mp.empty())
        {
            ListNode * minone  =mp.begin()->second;
            cur->next = new ListNode( minone->val);
            cur = cur->next;
            mp.erase( mp.begin());
            if( minone->next)
            {
                //mp[ minone->next->val] = minone->next;
                mp.insert( make_pair( minone->next->val, minone->next));
            }
        }
        return head->next;
    }
};