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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* tHead = new ListNode(0);
		tHead->next = head;
		ListNode* tCurNode = tHead;
		ListNode* tNext = tHead->next;
		while (tNext)
		{
			if(tNext->val == val){
				tCurNode->next = tNext->next;
				free(tNext);
				tNext=tCurNode->next;
			}else
			{
				tCurNode = tNext;
				if(tCurNode==NULL){
					break;
				}
				else
				{
					tNext = tCurNode->next;
				}
			}
		}
		return tHead->next;
    }
};