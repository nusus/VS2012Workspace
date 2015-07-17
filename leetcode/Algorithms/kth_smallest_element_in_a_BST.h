#ifndef kth_smallest_element_in_a_BST_h__
#define kth_smallest_element_in_a_BST_h__

#include<assert.h>
#include<vector>
#include "utility.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef CTreeNode<int> TreeNode;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        assert(root!=NULL&&k>0);
		std::vector<int> treeValues;
		treeValues.reserve(k);
		dumpBST(root,treeValues);
		return treeValues.at(k-1);
    }

	void dumpBST(TreeNode* root,std::vector<int>& ret){
		if(root==NULL) return;
		dumpBST(root->left,ret);
		ret.push_back(root->val);
		dumpBST(root->right,ret);
	}
};
#endif // kth_smallest_element_in_a_BST_h__
