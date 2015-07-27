#pragma  once

#include "utility.h"
using namespace utility;

typedef CListNode<int> ListNode;

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
    ListNode* rotateRight(ListNode* head, int k) {
		if(head==nullptr) return head;
		int len = 0;
		ListNode* p = head;
		ListNode* pOldTail = p;
		while(p)
		{
			if(!(p->next)) pOldTail = p;
			len ++;
			p = p->next;
		}
		k = k % len;
		if(k <= 0 ) return head;
		ListNode* pNewHead = head;
		ListNode* pNewTail = head;
		int nSteps = len - k;
		while (nSteps-1)
		{
			pNewTail = pNewTail->next;
			nSteps--;
		}
		pNewHead = pNewTail->next;
		pOldTail->next = head;
		pNewTail->next = NULL;
		return pNewHead;
    }
};