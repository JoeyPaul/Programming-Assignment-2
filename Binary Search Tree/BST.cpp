#include <fstream>
#include "BST.h"


void BST::insert(StudentNode* newStudent)
{
    //IF the root is NULL(tree is empty), then make this student the root
    if (root == NULL)
    {
        root = newStudent;
        return; // exit function early, we are done here.
    }

    //some pointers to help us navigate the tree to find where to put the new root
    StudentNode* current = root; //current node we're point at
    StudentNode* parent = NULL; //parent of current (node visited last time)

    while (true) //infinite loop
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT
        //if new students studentID is (less than) the student at current node
        //then go down LEFT
        if (newStudent->studentID < current->studentID)
        {
            // "<" (less than) means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our student
            if (current == NULL)
            {
                //done! put student here
                parent->leftChild = newStudent;
                return;//done, leave function
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            // if current is null insert here
            if (current == NULL)
            {
                parent->rightChild = newStudent;
                return;
            }
        }

    }
}

StudentNode* BST::search(int studentID, bool showSearchPath)
{
    //if tree empty, can't find student matching studentID then 
    if (root == NULL)
    {
        return NULL;
    }

    StudentNode* current = root;

    //keep looping until we find a match
    while (current->studentID != studentID)
    {

        if (showSearchPath)
            cout << current->studentID << " " << current->name << endl;

        //haven't found it yet, lets explore left or right down in the tree
        if (studentID < current->studentID)
        {
            //go left
            current = current->leftChild;
        }
        else
        {
            //go right
            current = current->rightChild;
        }

        //if current is NULL, search studentID cannot be found
        if (current == NULL)
        {
            return NULL;
        }
    }
    return current; //should be pointing to match in tree 
}

//outputs data in tree in accending order
//for decending make it call the rightChild first. 
void BST::inOrderTraversal(StudentNode* current)
{
    //keeps calling until it finds an empty node
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        cout << current->studentID << " " << current->name << endl;
        inOrderTraversal(current->rightChild);
    }
}

void BST::preOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        cout << current->studentID << " " << current->name << endl;
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }
}

void BST::postOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
        cout << current->studentID << " " << current->name << endl;
    }
}

void BST::show(StudentNode* p)
{
    //Base Case
    if (root == NULL) return;

    //setting up output file
    ofstream writeFile;
    writeFile.open("output-q1a2.txt");

    //create an empty queue for level order traversal
    queue<StudentLevelNode> q;

    //Enqueue Root and initialize height
    q.push(StudentLevelNode(root, 0));
    //Create a variable to store the previous level
    int previousOutputLevel = -1;

    while (q.empty() == false)
    {
        //print front of queue and remove it from queue
        StudentLevelNode node = q.front();
        if (node.level != previousOutputLevel)
        {
            cout << endl;
            cout << node.level << ": ";
            writeFile << endl;
            writeFile << node.level << ": ";
            previousOutputLevel = node.level;
        }
        //outputs the student ID numbers
        cout << node.student->studentID << " ";
        writeFile << node.student->studentID << " ";
        // removes from queue
        q.pop();
        
        //Enqueue left child
        if (node.student->leftChild != NULL)
            q.push(StudentLevelNode(node.student->leftChild, node.level + 1));
        //Enqueue right child
        if (node.student->rightChild != NULL)
            q.push(StudentLevelNode(node.student->rightChild, node.level + 1));
    }
    writeFile.close();
}
