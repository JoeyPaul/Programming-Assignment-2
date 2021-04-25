#include <fstream>
#include "BinaryMaxHeap.h"

int BinaryMaxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    //Returns
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int BinaryMaxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int BinaryMaxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

//after inserting, we heapify up from the position the new student number is inserted 
//compares current node to parent, swaps the bigger to the top
//recursive function, after each swap we call heapifyup again, to check against the next value
void BinaryMaxHeap::heapifyUp(int index)
{
    //if index is not the root(top of the tree)
    //AND parent index within heap bounds (not negative)
    //AND checks the current students ID against the parent nodes ID   -- (change to < for Minheap)
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].studentID > heap[parentIndex(index)].studentID)
    {
        //swap values between current node and parent
        StudentNode temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        //now we have swapped, run heapifyup again recursively on the parent above
        heapifyUp(parentIndex(index));
    }
}

//down is less efficient because we have to compare both children before moving down
//usually called when root of tree is destroyed
//recursive function, keeps calling itself as it swaps down the tree
void BinaryMaxHeap::heapifyDown(int index)
{
    //get left and right children indexes and compare them 
    int childLeft = leftChildIndex(index);
    int childRight = rightChildIndex(index);
    //child variable representing path move down from 
    int childIndex = childLeft; 
    //IF childL is not -1 and childR is not -1                   // change  '<' to '>' for min heap
    //AND left childs rank is less than right                         '  '
    if (childLeft >= 0 && childRight >= 0 && heap[childLeft].studentID < heap[childRight].studentID)
    {
        //make right child index the focus instead of left
        childIndex = childRight;
    }
    //IF childIndex is not root node AND is not -1
    //AND current nodes smaller than child nodes
    if (childIndex > 0 && heap[index].studentID < heap[childIndex].studentID)
    {
        //we should swap current with child, because we want the biggest ones closest to the top
        StudentNode temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;
        //recurse further down
        heapifyDown(childIndex);
    }
}

//inserts at the lowest, free spot in the tree, keeping data balanced
void BinaryMaxHeap::insert(StudentNode element)
{
    heap.push_back(element);
    heapifyUp(heap.size() - 1);
}

void BinaryMaxHeap::insertWithoutHeapify(StudentNode element)
{
    heap.push_back(element);
}

void BinaryMaxHeap::deleteMin()
{
    //can't delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty! Can't delete!" << endl;
        return;
    }
    //copy value in last element into root
    heap[0] = heap[heap.size() - 1]; //tutorial used heap.at(heap.size()-1)
    //delete last element
    heap.pop_back();
    //then heapifyDown starting from root (index 0)
    heapifyDown(0);
    cout << "Root Student Deleted From Database" << endl;
}

//get the root node from the heap tree structure (or first element in our vector)
StudentNode* BinaryMaxHeap::extractMin()
{
    //heaps empty, no numbers to return
    if (heap.size() == 0)
        return NULL;
    else
        return &(heap.front()); //return memory address of data at the front of the array
}

void BinaryMaxHeap::showHeap(int firstLine)
{
    //We don't want to overwrite what has potentially already been written to the text file
    //so we use ios:ate and ios::app to make sure we start output at the end of what is already in the file
    ofstream writeFile;
    writeFile.open("output-q2a2.txt", ios::ate | ios::app);
    for (StudentNode s : heap)
    {
        cout << s.studentID << " ";
        writeFile << s.studentID << " ";
    }
    cout << endl;
    writeFile << endl;
    writeFile.close();

}

int BinaryMaxHeap::size()
{
    return heap.size();
}
