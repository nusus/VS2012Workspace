#pragma once
typedef int ElementType;

struct AvlNode 
{
	ElementType Element;
	struct AvlNode* Left;
	struct AvlNode* Right;
	int Height;
};

typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree root);
Position Find(ElementType x, AvlTree root);
Position FindMin(AvlTree root);
Position FindMax(AvlTree root);
AvlTree Insert(ElementType x, AvlTree root);
AvlTree Delete(ElementType x, AvlTree root);
ElementType Retrieve(Position pos);
Position LeftRotate(Position k2);
Position RightRotate(Position k2);
Position LeftRightRotate(Position k3);
Position RightLeftRotate(Position k3);
