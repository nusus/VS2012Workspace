#pragma  once

#include "utility.h"
using namespace utility;

typedef CListNode<int> ListNode;
typedef CTreeNode<int> TreeNode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//ÖÐµÝ¹é
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		int len =0 ;
		ListNode* tmp = head;
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
		return sortedListToBSTImpl(head,0,len-1);

    }

	TreeNode* sortedListToBSTImpl(ListNode* &head,int start,int end)
	{
		if(start>end) return NULL;
		int mid = (start+end)/2;
		TreeNode* pLeftNode = sortedListToBSTImpl(head,start,mid-1);
		TreeNode* root = new TreeNode(head->val);
		root->left = pLeftNode;
		head = head->next;
		TreeNode* pRightNode = sortedListToBSTImpl(head,mid+1,end);
		root->right  = pRightNode;
		return root;
	}

};