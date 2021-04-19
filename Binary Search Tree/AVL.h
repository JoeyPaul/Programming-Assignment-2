#pragma once
#include "BST.h"

//AVL is a self balancing binary search tree
// AVL - Adelson, Velski & Landis (the names of the dudes who made the tree)
class AVL : public BST
{

public:
	bool displayRotations = true;

	//works out height of sub tree
	int height(StudentNode* node);

	//difference between left and right sub trees
	int difference(StudentNode* node);

	//ROTATIONS 
	//returns the final parent of the subset which is being rotated
	//return new parent of subtree
	//parameter: current parent of sub tree 
	//right branch, right child - right right rotation
	StudentNode* RRrotation(StudentNode* parent);
	//left branch, left child - left left rotation
	StudentNode* LLrotation(StudentNode* parent);
	//left branch, right child - left right rotation
	StudentNode* LRrotation(StudentNode* parent);
	//right branch, left child - right left rotation
	StudentNode* RLrotation(StudentNode* parent);

	//BALANCE 
	//balances a tree structure where parent is the middle top node
	//returns new parent after balancing(rotations)
	StudentNode* balance(StudentNode* parent);

	//INSERT
	//recursive insert that considers parent a sub tree
	//this insert also balances itself
	//returns new root node of the tree
	StudentNode* insertAVL(StudentNode* parent, StudentNode* newStudent);

	//overriding insert from parent
	void insert(StudentNode* newStudent);


};

