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
    void reorderList(ListNode* head) {
        if(head ==nullptr && head->next==nullptr && head->next->next==nullptr) return;
		head = mergeList(head,reverseList(spliteList(head)));

    }

	ListNode* mergeList(ListNode* l1, ListNode* l2){
		ListNode* pRet = l1;
		if (l1==nullptr || l2==nullptr)
		{
			pRet =  l1?l1:l2;
		}
		while (l1 && l2)
		{
			ListNode* pNext1 = l1->next;
			ListNode* pNext2 = l2->next;
			l1->next = l2;
			l2->next = pNext1;
			l1 = pNext1;
			l2 = pNext2;
		}
		return pRet;
	}

	ListNode* spliteList(ListNode* head){
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* pSlowNode = head;
		ListNode* pFastNode = head->next;
		while ( pFastNode!=NULL && pFastNode->next!=NULL )
		{
			pSlowNode = pSlowNode->next;
			pFastNode = pFastNode->next->next;
		}
		ListNode* pRet = pSlowNode->next;
		pSlowNode->next = nullptr;
		return pRet;
	}

	ListNode* reverseList(ListNode* head){
		ListNode* p1 = head;
		if (p1==nullptr || p1->next ==nullptr)
		{
			return p1;
		}
		ListNode* p2 = p1->next;
		ListNode* p3 = p2->next;
		p1->next = nullptr;
		p2->next = p1;
		p1=p2;
		p2=p3;
		while (p2!=nullptr)
		{
			p3 = p2->next;
			p2->next = p1;
			p1=p2;
			p2=p3;
		}
		return p1;

	}
	
};