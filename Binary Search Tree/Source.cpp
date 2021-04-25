#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "AVL.h"
#include "BinaryMaxHeap.h"

using namespace std;

int main()
{
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
	int i = 0;
	do
	{
		int temp;
		readFile >> temp;
		avlQuestion1.insert(new StudentNode(temp, " "));
		i++;
	} while (i != firstLine);//(readFile.peek() != EOF); // keep storing numbers until the end of the text file

	//Loops through the text file again storing into a vector, I was trying to solve a bug with EOF, that is why they are seperate.
	readFile.close();
	readFile.open("input-q1a2.txt");
	readFile >> firstLine;
	do
	{
		int temp;
		readFile >> temp;
		nums.push_back(temp);
	} while (readFile.peek() != EOF);

	//checks for errors: line 1 doesn't match the amount on line 2
	if (nums.size() != firstLine)
	{
		cout << "ERROR! Line 2 must have the amount of numbers specified on line 1." << endl;
		return 0;
	}
	readFile.close();

	//-------------------------------------------------------------------------------------//
	//---------------------------------------OUTPUT----------------------------------------//
	//-------------------------------------------------------------------------------------//

	//outputs the data using breadth first traversal - outputs to the debug console and
	//                                                         the text file 
	avlQuestion1.show(avlQuestion1.root);

	//-------------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------//
	/*                                    ----------                                       */
	/*                                   |    Q 2   |                                      */
	/*                                    ----------                                       */
	//-------------------------------------------------------------------------------------//
	//----------------------------------INPUT-&-OUTPUT-------------------------------------//
	//-------------------------------------------------------------------------------------//
	
	cout << endl << endl;
	//Open up and read the text file again
	readFile.open("input-q1a2.txt");
	readFile >> firstLine; // we want to skip over the first number this time

	//store all the numbers on the second line in two different heaps and print them as we go
	//the second heap will store the same data but won't heapify the data
	BinaryMaxHeap bmhQuestion2;
	BinaryMaxHeap bmhNoHeapify;
	i = 0;
	do
	{
		int temp;
		readFile >> temp;
		bmhQuestion2.insert(StudentNode(temp, " "));
		bmhNoHeapify.insertWithoutHeapify(StudentNode(temp, " "));
		bmhQuestion2.showHeap(firstLine);
		bmhNoHeapify.showHeap(firstLine);
		i++;
	} while (i != nums.size());//(readFile.peek() != EOF); // keep storing numbers until the end of the text file
	readFile.close();
	system("pause");
	return 0;
}