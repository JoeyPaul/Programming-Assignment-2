#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "StudentNode.h"

using namespace std;

class BinaryMaxHeap
{
public:
	vector<StudentNode> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyUp(int index);
	void heapifyDown(int index);

	void insert(StudentNode element);
	void insertWithoutHeapify(StudentNode element);
	void deleteMin();
	StudentNode* extractMin();
	void showHeap(int firstLine);
	int size();
};

