#pragma once
#include "utility.h"

using namespace utility;
typedef CTreeNode<int> TreeNode;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeImpl(preorder.begin(),
			preorder.end(),
			inorder.begin(),
			inorder.end());
    }

	TreeNode* buildTreeImpl(
		vector<int>::iterator preorder_begin, 
		vector<int>::iterator preorder_end, 
		vector<int>::iterator inorder_begin,
		vector<int>::iterator inorder_end) {
			if(preorder_begin == preorder_end || inorder_begin == inorder_end) return NULL;
			int root_value = *(preorder_begin);
			TreeNode* root = new TreeNode(root_value);

			vector<int>::iterator root_position = find(inorder_begin, inorder_end, root_value);
			root->left = buildTreeImpl(preorder_begin + 1,
				preorder_begin + 1 + (root_position - inorder_begin),
				inorder_begin,
				root_position);
			root->right = buildTreeImpl(preorder_begin + 1 + (root_position - inorder_begin),
				preorder_end,
				root_position +1, 
				inorder_end);
			return root;
	}
};