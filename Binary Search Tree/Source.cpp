#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "AVL.h"

using namespace std;

int main()
{
	BST bst1;
	//One way to dynamically add students 
	//StudentNode* sNodePtr = new StudentNode(123, "asads");
	//bst1.insert(sNodePtr);

	//here is a quicker way
	bst1.insert(new StudentNode(3433, "Jeff"));
	bst1.insert(new StudentNode(2222, "Bill"));
	bst1.insert(new StudentNode(1221, "Trevor"));
	bst1.insert(new StudentNode(4533, "Homie"));
	bst1.insert(new StudentNode(3333, "Studded Bull"));
	bst1.insert(new StudentNode(6666, "Gift From God"));
	bst1.insert(new StudentNode(7777, "Harry"));
	bst1.insert(new StudentNode(4343, "Marcus Von Don Son"));

	cout << "try find student matching id:1221..." << endl;
	StudentNode* sPtr = bst1.search(1221, true);

	if (sPtr == NULL)
		cout << "Cannot find a student matching that ID." << endl;
	else cout << "Found " << sPtr->name << " with id: 1221" << endl;

	//StudentNode* sPtr2 = bst1.search(-1, true);

	cout << endl << "Students inorder traversal" << endl;
	cout << "++++++++++++++++++++++++++" << endl;
	bst1.inOrderTraversal(bst1.root);

	cout << endl << "Students preorder traversal" << endl;
	cout << "++++++++++++++++++++++++++" << endl;
	bst1.preOrderTraversal(bst1.root);
	
	cout << endl << "Students postorder traversal" << endl;
	cout << "++++++++++++++++++++++++++" << endl;
	bst1.postOrderTraversal(bst1.root);

	cout << endl << endl;
	//----------------------------AVLTREE--------------------------------//
	cout << "AVL" << endl;
	cout << "===" << endl;
	AVL avl1;
	avl1.displayRotations = true;
	avl1.insert(new StudentNode(2333, "Jeff"));
	avl1.insert(new StudentNode(2222, "Bill"));
	avl1.insert(new StudentNode(9797, "Jank"));
	cout << "Tree height thus far: " << avl1.height(avl1.root) << endl;
	avl1.insert(new StudentNode(4253, "Sanga"));
	avl1.insert(new StudentNode(1912, "Ciggy"));
	avl1.insert(new StudentNode(8545, "Geoff"));
	avl1.insert(new StudentNode(2221, "Alabama"));
	avl1.insert(new StudentNode(7575, "Biscuit"));
	cout << "AVL ROOT : " << avl1.root->name << " " << avl1.root->studentID << endl;
	cout << "Students AVL inorder traversal" << endl;
	cout << "==============================" << endl;
	avl1.inOrderTraversal(avl1.root);


	cout << "try find student matching id:7575..." << endl;
	StudentNode* sPtr2 = avl1.search(7575, true);
	if (sPtr2 != NULL)
		cout << "7575 " << sPtr2->name << " was found with matching ID" << endl;
	else 
		cout << "Cannot find id with 7575 in AVL Tree" << endl;

	bst1.show(bst1.root);
	avl1.show(avl1.root);

	//-------------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------//
	/*                                    ----------                                       */
	/*                                   |    Q 1   |                                      */
	/*                                    ----------                                       */
	//-------------------------------------------------------------------------------------//
	//---------------------------------------INPUT-----------------------------------------//
	//-------------------------------------------------------------------------------------//

//reading from a file
	ifstream readFile;
	readFile.open("input-q1a2.txt");
	//check what is on the first line of the input text file
	int firstLine;
	readFile >> firstLine;
	
	//Check for valid input numbers on the first line
	if (firstLine == 0)
	{
		cout << "ERROR! Invalid input on the first line." << endl;   //check for errors in input
		return 0;
	}
	else if (firstLine < 0)
	{
		cout << "ERROR! Invalid Input on the first line. Input must be greater than (0)" << endl;
		return 0;
	}

	//Loop through all the numbers on the 2nd line
	//Storing them in a temporary int and then pushing them into an AVL tree each loop
	vector<int> nums;
	AVL avlQuestion1;
	do
	{
		int temp;
		readFile >> temp;
		avlQuestion1.insert(new StudentNode(temp, " "));
		nums.push_back(temp); // storing in a vector to, just incase an extra " " is added at the end of the input text file
	} while (readFile.peek() != EOF); // keep storing numbers until the end of the text file

	//This gets rid of a bug I was getting where it duplicated the last element of the vector if 
	//there was a ' ' at the end of the input file
	if (nums.size() != firstLine)
	{
		nums.pop_back();
	}

	//checks for errors: line 3 doesn't match the amount on line 4
	if (nums.size() != firstLine)
	{
		cout << "ERROR! Line 2 must have the amount of numbers specified on line 1." << endl;
		return 0;
	}
	readFile.close();

	//-------------------------------------------------------------------------------------//
	//---------------------------------------OUTPUT----------------------------------------//
	//-------------------------------------------------------------------------------------//

	
	avlQuestion1.show(avlQuestion1.root);

	


	//-------------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------//
	/*                                    ----------                                       */
	/*                                   |    Q 2   |                                      */
	/*                                    ----------                                       */
	//-------------------------------------------------------------------------------------//
	//---------------------------------------INPUT-----------------------------------------//
	//-------------------------------------------------------------------------------------//

	system("pause");
	return 0;
}