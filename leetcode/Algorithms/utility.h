#ifndef utility_h__
#define utility_h__
#include <assert.h>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

namespace utility{

	using namespace std;

/************************************************************************/
/* Definition for a binary tree node. BEGIN                                                                     */
/************************************************************************/
template<typename T>
struct CTreeNode {
    T val;
    CTreeNode *left;
    CTreeNode *right;
    CTreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template<typename T> 
void InsertValToTree(CTreeNode<T>*,const T&);

template <typename T>
CTreeNode<T>* InitTree(const vector<T>& vValues);

template<typename T>
void PrintTree(const CTreeNode<T>* root);

template<typename T>
void DumpTree(const CTreeNode<T>* root,std::vector<T>& ret);


template <typename T>
CTreeNode<T>* InitTree(const vector<T>& vValues){
	assert(!vValues.empty());
	CTreeNode<T>* root = new CTreeNode<T>(vValues[0]);
	for_each(vValues.begin()+1,vValues.end(),InsertValToTree<T>);
}
//
template<typename T>
void InsertValToTree(CTreeNode<T>* root,const T& val){
	assert(root!=NULL);
	if(val<root->value){
		if(root->left==NULL){
			CTreeNode<T> pLeftNode = new CTreeNode<T>(val);
			root->left = pLeftNode;
		}else
		{
			InsertValToTree(root->left,val);
		}
	}else
	{
		if(root->right==NULL){
			CTreeNode<T> pRightNode = new CTreeNode<T>(val);
			root->right = pRightNode;
		}else
		{
			InsertValToTree(root->right,val);
		}
	}
}

template<typename T>
void PrintTree(const CTreeNode<T>* root){
	if(root==NULL) return;
	PrintTree(root->left);
	cout<<root->val<<" ";
	PrintTree(root->right);
}

template<typename T>
void DumpTree(const CTreeNode<T>* root,std::vector<T>& ret){
	if(root==NULL) return;
	DumpTree(root->left,ret);
	ret.push_back(root->val);
	DumpTree(root->right,ret);
}
/************************************************************************/
/* TreeNode END                                                                     */
/************************************************************************/


/************************************************************************/
/*Definition for singly-linked list begin                                                                      */
/************************************************************************/
template<typename T>
struct CListNode {
     T val;
	 CListNode *next;
     CListNode(T x) : val(x), next(NULL) {}
};

template <typename T>
CListNode<T>* InitList(const vector<T>& vals);

template <typename T>
void InsertValToList(CListNode<T>* position,const T& val);

template<typename T>
void PushBackValToList(CListNode<T>* head, const T& val);

template<typename T>
void PushFrontValToList(CListNode<T>* head, const T& val);

template<typename T>
void PrintList(const CListNode<T>* head);

template<typename T>
void DumpList(const CListNode<T>* head, vector<T>& vec);

template<typename T>
void SortList(CListNode<T>* head);

template<typename T>
void ClearList(CListNode<T>* head);

template <typename T>
size_t LengthList(CListNode<T>* head);

template<typename T>
T& ListAt(CListNode<T>* head, size_t index){
	assert(head!= NULL && LengthList(head)>= (index+1));
	for (;index>0 , head!=NULL ;index--){
		head = head->next;
	}
	return head->val;
}

template <typename T>
CListNode<T>* InitList(const vector<T>& vals){
	assert(!vals.empty());
	CListNode<T>* head = new CListNode<T>(vals[0]);
	head->next = NULL;
	for (auto ite = vals.begin()+1; ite != vals.end(); ite++)
	{
		PushBackValToList(head,*ite);
	}
	return head;
}


template<typename T>
void PushBackValToList( CListNode<T>* head, const T& val )
{
	assert(head!=NULL);
	while (head->next)
	{
		head = head->next;
	}
	CListNode<T>* next = new CListNode<T>(val);
	next->next = NULL;
	head->next = next;
	//return head;
}

template<typename T>
CListNode<T>* PushFrontValToList(CListNode<T>* head, const T& val){
	assert(head!=NULL);
	CListNode<T>* next = head;
	CListNode<T>* tNode = new CListNode<T>(val);
	tNode->next = next;
	return tNode;
}

template<typename T>
void PrintList(const CListNode<T>* head){
	assert(head!=NULL);
	while (head)
	{
		cout<<head->val<<" ";
		head  = head->next ;
	}
}

template<typename T>
void ClearList(CListNode<T>* head){
	if(head == NULL) return;
	CListNode<T>* tCurNode = head;
	CListNode<T>* tNextNode;
	while (tCurNode)
	{
		tNextNode = tCurNode->next;
		delete tCurNode;
		tCurNode = tNextNode;
	}
}

template <typename T>
size_t LengthList(CListNode<T>* head){
	assert(head!=NULL);
	CListNode<T>* tCurNode = head;
	size_t ret=0;
	while (tCurNode)
	{
		ret++;
		tCurNode = tCurNode->next;
	}
	return ret;
}

template<typename T>
void DumpList(const CListNode<T>* head, vector<T>& vec){
	assert(head != NULL);
	vec.clear();
	vec.reserve(LengthList(head));
	while (head)
	{
		vec.push_back(head->val);
		head = head->next;
	}
}

template <typename T>
void InsertValToList(CListNode<T>* position,const T& val){
	assert(position != NULL);
	CListNode<T>* tNextNode = position->next;
	CListNode<T>* tInsertNode = new CListNode<T>(val);
	tInsertNode->next = tNextNode;
	position->next = tInsertNode;
	return;
}

}
#endif // utility_h__
