#pragma once

typedef int ElementType;
struct TreeNode
{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree root);
Position Find(ElementType x, SearchTree root);
Position FindMin(SearchTree root);
Position FindMax(SearchTree root);
SearchTree Insert(ElementType x, SearchTree root);
SearchTree Delete(ElementType x, SearchTree root);
ElementType Retrieve(Position pos);

