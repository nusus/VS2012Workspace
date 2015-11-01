#pragma once 
#include "utility.h"

using namespace utility;

typedef CTreeNode<int>  TreeNode;

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTreeImpl(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}

	TreeNode* buildTreeImpl(
		vector<int>::iterator inorder_begin, 
		vector<int>::iterator inorder_end, 
		vector<int>::iterator postorder_begin, 
		vector<int>::iterator postorder_end) {
			if ( inorder_begin == inorder_end || postorder_begin == postorder_end) return NULL;
			int root_value = *(postorder_end - 1);
			TreeNode *root = new TreeNode(root_value);
			vector<int>::iterator root_position = find(inorder_begin, inorder_end, root_value);
			root->left = buildTreeImpl(
				inorder_begin, 
				root_position, 
				postorder_begin, 
				postorder_begin + (root_position - inorder_begin));
			root->right = buildTreeImpl(
				root_position + 1,
				inorder_end,
				postorder_begin + (root_position - inorder_begin),
				postorder_end - 1);

			return root;
	}
};