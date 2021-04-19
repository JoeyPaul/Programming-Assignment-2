#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "StudentNode.h"

using namespace std;

//Helper class for output
class StudentLevelNode
{
public:
	StudentNode* student;
	int level;

	//constructor
	StudentLevelNode(StudentNode* student, int level)
	{
		this->student = student;
		this->level = level;
	}
};



//Binary Search Tree
//root node sort of acting as centre
//everything smaller than root is stored on left branch
//everything else to the right
class BST
{
public:
	StudentNode* root = NULL;
	virtual void insert(StudentNode* newStudent);
	StudentNode* search(int studentID, bool showSearchPath = false);

	//recursive traversal functions
	void inOrderTraversal(StudentNode* current);
	void preOrderTraversal(StudentNode* current);
	void postOrderTraversal(StudentNode* current);

	//show 
	void show(StudentNode* p);
};

