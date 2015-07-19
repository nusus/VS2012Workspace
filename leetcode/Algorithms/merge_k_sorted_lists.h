#pragma once
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		ListNode* pHead = new ListNode(-1);
		ListNode* pCurNode = pHead;
		while (l1!=NULL && l2!=NULL)
		{
			if(l1->val < l2->val){
				pCurNode->next = l1;
				l1 = l1->next;
			}else
			{
				pCurNode->next = l2;
				l2 = l2->next;
			}
			pCurNode = pCurNode->next;
		}
		if (l1==NULL)
		{
			pCurNode->next = l2;
		}
		if(l2==NULL){
			pCurNode->next = l1;
		}
		pCurNode = pHead->next;
		delete pHead;
		pHead = NULL;
		return pCurNode;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int length = lists.size();
		if(length==0) return NULL;
		if(length==1) return lists[0];
		int mid = length/2;
		vector<ListNode*> vecLeft(lists.begin(),lists.begin()+mid);
		vector<ListNode*> vecRight(lists.begin()+mid,lists.end());
		return mergeTwoLists(mergeKLists(vecLeft),mergeKLists(vecRight));
    }
};