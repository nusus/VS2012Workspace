#ifndef utility_h__
#define utility_h__
#include <assert.h>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
//Definition for a binary tree node.
template<typename T>
struct CTreeNode {
    T val;
    CTreeNode *left;
    CTreeNode *right;
    CTreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
CTreeNode<T>* InitTree(const vector<T>& vValues){
	assert(!vValues.empty());
	CTreeNode<T>* root = new CTreeNode<T>(vValues[0]);
	for_each(vValues.begin()+1,vValues.end(),InsertValToTree<T>);
}
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

#endif // utility_h__
