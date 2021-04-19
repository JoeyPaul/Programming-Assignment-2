#pragma once
#include <iostream>
#include <string>

using namespace std;

class StudentNode
{
public:
	int studentID;
	string name;
	StudentNode* leftChild;
	StudentNode* rightChild;

	StudentNode(int studentID, string name);

};

