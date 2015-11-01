#pragma once
#include <string>
#include <list>
#include <queue>
#include <numeric>

#include "utility.h"
#include <stdlib.h>


using namespace utility;
using namespace std;
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return join(parseTree(root), ',', '[', ']');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> split_result = split(data, "[,]");
		if(split_result.empty()) return NULL;

		queue<TreeNode*> queue_tree_node;
		for (list<string>::iterator itr = split_result.begin(); itr != split_result.end(); ++itr)
		{
			int is_null = (*itr).compare("null");
			if( is_null == 1){
				queue_tree_node.push(NULL);
			}
			else
			{
				int val = stoi((*itr));
				TreeNode* tmp_node = new TreeNode(val);
				tmp_node->left = NULL;
				tmp_node->right = NULL;
				queue_tree_node.push(tmp_node);
			}
		}

		queue<TreeNode*> tmp_queue;
		TreeNode* root = queue_tree_node.front();
		tmp_queue.push(root);
		queue_tree_node.pop();

		TreeNode* cur_node;
		while ( !tmp_queue.empty())
		{
			cur_node = tmp_queue.front();
			tmp_queue.pop();

			if (queue_tree_node.empty())
			{
				break;
			}
			cur_node->left = queue_tree_node.front();
			queue_tree_node.pop();
			if ( cur_node->left != NULL)
			{
				tmp_queue.push(cur_node->left);
			}

			if(queue_tree_node.empty())
			{
				break;
			}
			cur_node->right  = queue_tree_node.front();
			queue_tree_node.pop();
			if( cur_node->right != NULL )
			{
				tmp_queue.push(cur_node->right);
			}
		}
		return root;
    }

	string join(const list<string> list_str, 
				const char delimiter, 
				const char begin , 
				const char end) 
	{
		if (list_str.empty())
		{
			return string();
		}

		int str_length = 0;
		str_length = accumulate(list_str.begin(), list_str.end(), 0, CountLength());
		str_length = str_length + list_str.size() - 1 + 2;

		string ret(str_length + 1, '\0');
		int last_index = 0 ;

		ret[last_index++] = begin;
		copy( (*list_str.begin()).begin(), ((*list_str.begin()).end()), ret.begin() + (last_index ));	
		last_index += (*list_str.begin()).length();
		for (list<string>::const_iterator itr = ++(list_str.begin()); itr != list_str.end(); ++itr)
		{
			ret[last_index++] = delimiter;
			copy( (*itr).begin(), (*itr).end(), ret.begin() + (last_index));
			last_index += (*itr).size();
		}
		ret[str_length -1] = end;
		return ret;
	}

	list<string> parseTree(TreeNode* root) {
		list<string> ret;
		queue<TreeNode*> tree_node_queue;
		tree_node_queue.push(root);

		while ( !tree_node_queue.empty())
		{
			TreeNode* curNode = tree_node_queue.front();
			if(curNode == nullptr) 
				ret.emplace_back("null");
			else
			{
				ret.push_back(to_string(curNode->val));
				tree_node_queue.push( curNode->left);
				tree_node_queue.push( curNode->right);
			}
			tree_node_queue.pop();
		}

		return ret;
	}

	list<string> split(const string src, const char* delimiters) {
		int src_length = src.size();
		if( src_length == 2) return list<string>();
		char *src_tmp = new char[src_length + 1];
		strcpy(src_tmp, src.c_str());
		src_tmp[src_length] = '\0';
		char* cur_index = strtok(src_tmp, delimiters);
		char* last_index = cur_index;

		list<string> ret;
		while (true)
		{
			last_index = cur_index;
			cur_index = strtok(NULL, delimiters);
			if (cur_index != NULL)
			{
				ret.emplace_back(last_index, cur_index - last_index);
			}
			else
			{
				if( src_tmp+src_length-last_index-1 > 0)
					ret.emplace_back(last_index, src_tmp+src_length-last_index-1);
				break;
			}
		}
		delete src_tmp;
		return ret;
	}

	struct CountLength 
	{
		int operator() (int init, const string str) {
			return init + str.length(); 
		}
	};
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));