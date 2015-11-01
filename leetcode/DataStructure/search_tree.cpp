#include "search_tree.h"
#include <stdlib.h>
#include <assert.h>
#define  NULL 0



SearchTree MakeEmpty( SearchTree root )
{
	if( root != NULL){
		MakeEmpty(root->Left);
		MakeEmpty(root->Right);
		free(root);
	}
	return NULL;
}

Position Find( ElementType x, SearchTree root )
{
	if(root == NULL) return NULL;
	if(root->Element == x) return root;
	if(x< root->Element) Find(x, root->Left);
	if(x> root->Element) Find(x, root->Right);
}

Position FindMin( SearchTree root )
{
	if(root == NULL) return NULL;
	else
	{
		if(root->Left) return FindMin(root->Left);
		else
		{
			return root;
		}
	}
}

Position FindMax( SearchTree root )
{
	if(root == NULL) return NULL;
	else
	{
		if(root->Right) return FindMax(root->Right);
		else
		{
			return root;
		}
	}
}

SearchTree Insert( ElementType x, SearchTree root )
{
	if(root == NULL){
		root = (SearchTree)malloc(sizeof(struct TreeNode));
		if(root ==NULL) exit(1);
		root->Left = NULL;
		root->Right = NULL;
		root->Element = x;
	}else
	{
		if(x < root->Element){
			root->Left = Insert(x, root->Left);
		}else if(x > root->Element){
			root->Right = Insert(x, root->Right);
		}
	}
	return root ;
	//assert(root!=NULL);
	//if (x<root->Element)
	//{
	//	if(root->Element == NULL)
	//	{
	//		Position tmpCell = (Position)malloc(sizeof(struct TreeNode));
	//		tmpCell->Element = x;
	//		tmpCell->Left = tmpCell->Right = NULL;
	//		root->Left = tmpCell;
	//	}
	//	else
	//	{
	//		root->Left = Insert (x, root->Left);
	//	}
	//}

}

SearchTree Delete( ElementType x, SearchTree root )
{
	Position tmpCell;
	if(root ==NULL) return NULL;
	if(x< root->Element){
		root->Left = Delete(x, root->Left);
	}
	else
	{
		if(x> root->Element){
			root->Right = Delete(x, root->Right);
		}
		else
		{
			if(root->Left && root->Right){
				tmpCell = FindMin(root->Right);
				root->Element = tmpCell->Element;
				root->Right = Delete(root->Element, root->Right);
			}
			else
			{
				tmpCell = root;
				if(root->Left ==NULL)
					root = root->Right;
				else if(root->Right ==NULL)
					root = root->Left;
				free(tmpCell);
			}
		}
	}

	return root;

}

ElementType Retrieve( Position pos )
{
	return pos->Element;
}


