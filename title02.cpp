//#define TITLE02
#ifdef TITLE02

//////////////////////////////////////////////////////////////////////////
// 02 - Add Two Numbers

//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8


#include <iostream>
#include <vector>
#include <string>

//////////////////////////////////////////////////////////////////////////
// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * cur = new ListNode(0);
		ListNode * head = cur;
		int pre = 0;
		int sum = 0;
		while (l1 || l2||pre)
		{
			sum = pre;
			if ( l1)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum += l2->val;
				l2 = l2->next;
			}

			pre = sum/10;
			sum %= 10;

			cur->next = new ListNode(sum);
			cur = cur->next;
		}
		return head->next;
	}
};


int main()
{
	Solution s;
	
	// List 1 (2->4->3)
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	// List 2 (5->6->4)
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	s.addTwoNumbers(l1, l2);
	return 0;
}

#endif