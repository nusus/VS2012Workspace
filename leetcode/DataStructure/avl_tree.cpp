#include "avl_tree.h"

#include <stdlib.h>
#define NULL 0

static int Height(AvlTree root)
{
	if(root ==NULL) return -1;
	return root->Height;
}

static int max(int lhs, int rhs){
	return lhs>rhs?lhs:rhs;
}

static int min(int lhs, int rhs)
{
	return lhs<rhs?lhs:rhs;
}


AvlTree MakeEmpty( AvlTree root )
{
	if(root !=NULL){
		MakeEmpty(root->Left);
		MakeEmpty(root->Right);
		free(root);
	}
	return NULL;
}

Position Find( ElementType x, AvlTree root )
{
	if(root == NULL) return NULL;
	if(x == root->Element)
		return root;
	if(x< root->Element)
		return Find(x, root->Left);
	if(x> root->Element)
		return Find(x, root->Right);
}

Position FindMin( AvlTree root )
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

Position FindMax( AvlTree root )
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

AvlTree Insert( ElementType x, AvlTree root )
{
	if(root == NULL){
		root = (AvlTree)malloc(sizeof(struct AvlNode));
		if(root ==NULL) exit(1);
		root->Element = x;
		root->Left = root->Right = NULL;
	}
	else
	{
		if(x<root->Element)
		{
			root->Left = Insert(x, root->Left);
			if(Height(root->Left) - Height(root->Right) ==2)
				if(x< root->Left->Element)
					root = RightRotate(root);
				else
					root = LeftRightRotate(root);
		}
		if(x>root->Element)
		{
			root->Right = Insert(x, root->Right);
			if(Height(root->Right) - Height(root->Left) ==2)
				if(x>root->Right->Element)
					root = LeftRotate(root);
				else
					root = RightLeftRotate(root);
		}
	}
	root->Height = max(Height(root->Left), Height(root->Right))+1;
	return root;
}

AvlTree Delete( ElementType x, AvlTree root )
{
	//TODO:simple idea to solve the problem.
	/**
	  *Give each node in th tree a extra attribute "balance".
	  *If Height(Node->Left) - Height(Node->Right) ==1,balance=-1;
	  *If Height(Node->Left) - Height(Node->Right) ==0,balance=0;
	  *If Height(Node->Left) - Height(Node->Right) ==-1,balance=1;
	  */
	return NULL;
}

Position LeftRotate( Position k2 )
{
	Position k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = max(Height(k2->Left), Height(k2->Right))+1;
	k1->Height = max(Height(k1->Left), k2->Height)+1;
	return k1;
}

Position RightRotate( Position k2 )
{
	Position k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;
	k2->Height = max(Height(k2->Left), Height(k2->Right))+1;
	k1->Height = max(Height(k1->Right), k2->Height)+1;
	return k1;
	
}

Position LeftRightRotate( Position k3 )
{
	Position k2 = k3->Right;
	k3->Right = LeftRotate(k2);
	return RightRotate(k3);
}

Position RightLeftRotate( Position k3 )
{
	Position k2 = k3->Left;
	k3->Left = RightRotate(k2);
	return LeftRotate(k3);
}

ElementType Retrieve(Position pos)
{
	return pos->Element;
}