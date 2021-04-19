#include "AVL.h"


//using recursion, we keep exploring down, and pass final height values up
int AVL::height(StudentNode* node)
{
    //height
    int h = 0;
    //this if statement breaks the recursion cycle when we find NULL at the bottom of the branches
    if (node != NULL)
    {
        int leftHeight = height(node->leftChild);
        int rightHeight = height(node->rightChild);

        //max returns the bigger of the 2 values
        int maxHeight = max(leftHeight, rightHeight);
        h = maxHeight + 1;
    }
    return h;
}

int AVL::difference(StudentNode* node)
{
    //if the tree is empty, it's balanced, it's 0
    if (node == NULL)
        return 0;

    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    int balanceFactor = leftHeight - rightHeight;

    return balanceFactor;
}

StudentNode* AVL::RRrotation(StudentNode* parent)
{
    StudentNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    if (displayRotations)
        cout << "RR rotation on " << parent->name << endl;

    return temp;
}

StudentNode* AVL::LLrotation(StudentNode* parent)
{
    StudentNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
        cout << "LL rotation on " << parent->name << endl;

    return temp;
}

//needs 2 rotations, rather than 1
//First: rotation rotates bottom 2 nodes, which turns the whole
//structure into a right-right rotation
//Second: rotation uses LLrotation
StudentNode* AVL::LRrotation(StudentNode* parent)
{
    StudentNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
        cout << "LR rotation is on " << parent->name << endl;
    return LLrotation(parent);
}

//same as above but the opposite
StudentNode* AVL::RLrotation(StudentNode* parent)
{
    StudentNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
        cout << "RL rotation is on " << parent->name << endl;
    return RRrotation(parent);
}

StudentNode* AVL::balance(StudentNode* parent)
{
    //get balance factor 
    int balanceFactor = difference(parent);

    //IF balanceFactor not within -1,-,1, then lets work out what rotations to do
    if (balanceFactor > 1)
    {
        //left branch is heavy, now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {
            //left child unbalanced 
            parent = LLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        //right branch is heavy, now work out is left or right child heavy
        if (difference(parent->rightChild) > 0)
        {
            //left child unbalanced 
            parent = RLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = RRrotation(parent);
        }
    }
    return parent;
}

StudentNode* AVL::insertAVL(StudentNode* parent, StudentNode* newStudent)
{
    //if subtree empty, this becomes the parent 
    if (parent == NULL)
    {
        parent = newStudent;
        return parent;
    }

    //parent not NULL, so we haven't found an
    //empty space to fit a newStudent yet
    //We need to go down either left or right path
    if (newStudent->studentID < parent->studentID)
    {
        parent->leftChild = insertAVL(parent->leftChild, newStudent);
        parent = balance(parent);
    }
    else // assume id >= parent's id
    {
        parent->rightChild = insertAVL(parent->rightChild, newStudent);
        parent = balance(parent);
    }
}

void AVL::insert(StudentNode* newStudent)
{
    cout << "Inserting " << newStudent->name << " " << newStudent->studentID << endl;
    root = insertAVL(root, newStudent);
    cout << endl;
}
