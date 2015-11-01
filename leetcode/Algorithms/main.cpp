//#include "unique_paths_II.h"
//#include "sort_search_position.h"
//#include "longest_palindromic_substring.h"
//#include "string_to_integer.h"
//#include "replace_blank.h"
//#include <stdio.h>
//#include "print_n_number.h"
//#include "palindrome_number.h"
//#include "serialize_and_deserialize_binary_tree.h"
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"
#include <iostream>
int main(){
	/*int a1[] = {2};
	int a2[] = {3,4};
	int a3[] = {6,5,7};
	int a4[] = {4,1,8,3};
	int a5[] = {1,3,5,6};
	vector<int> v1(a1,a1+1);
	vector<int> v2(a2,a2+2);
	vector<int> v3(a3,a3+3);
	vector<int> v4(a4,a4+4);
	vector<int> v5(a5,a5+4);
	vector<vector<int>> vva;
	vva.push_back(v1);
	vva.push_back(v2);
	vva.push_back(v3);
	vva.push_back(v4);
	Solution sol;
	int ret = sol.searchInsert(v5,7);*/
	/*string sTmp("  010  ");
	Solution sol;
	int ret = sol.myAtoi(sTmp);*/
	/*char src[] = "my happy day";
	ReplaceBlank(src, strlen(src));*/
	//utility::PrintNnumberImpl(2);
	/*Solution sol ; 
	bool ret1 = sol.isPalindrome(65556);
	bool ret2 = sol.isPalindrome(63364);
	bool ret3 = sol.isPalindrome(653356);*/
	/*Codec codec;
	TreeNode* tmp_node = codec.deserialize(string("[-1,0,1]"));
	string ser_src = codec.serialize(tmp_node);
	TreeNode* root = codec.deserialize(ser_src);*/

	int preorder[] = {1,2};
	int inorder[] = {1,2};
	vector<int> vec_inorder(preorder, preorder + 2);
	vector<int> vec_preorder(inorder, inorder + 2);
	Solution sol;
	TreeNode* root = sol.buildTree(vec_preorder, vec_inorder);
	getchar();
	return 0;
}