#ifndef sort_list_h__
#define sort_list_h__
#include "utility.h"

using namespace utility;
typedef CListNode<int> ListNode;


#include <assert.h>

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
    ListNode* sortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode* pLeftStart = head;
		ListNode* pLeftEnd = head;
		ListNode* pRightStart = head;
		ListNode* pFast = head->next->next;
		while (pFast!=NULL)
		{
			pLeftEnd = pLeftEnd->next;
			if ((pFast=pFast->next)!=NULL)
			{
				pFast = pFast->next;
			}
		}
		pRightStart = pLeftEnd->next;
		pLeftEnd->next = NULL;
		pLeftStart = sortList(pLeftStart);
		pRightStart = sortList(pRightStart);
		
		ListNode* tHead = new ListNode(0);
		ListNode* pCurNode = tHead;
		while (pLeftStart!=NULL && pRightStart!=NULL)
		{
			if(pLeftStart->val < pRightStart->val){
				pCurNode->next = pLeftStart;
				pLeftStart = pLeftStart->next;
			}else
			{
				pCurNode->next = pRightStart;
				pRightStart = pRightStart->next;
			}
			pCurNode = pCurNode->next;
		}
		if (pLeftStart == NULL)
		{
			pCurNode->next = pRightStart;
		}
		if(pRightStart == NULL){
			pCurNode->next = pLeftStart;
		}
		pCurNode = tHead->next;
		delete tHead;
		tHead = NULL;
		return pCurNode;
    }
};
#endif // sort_list_h__
