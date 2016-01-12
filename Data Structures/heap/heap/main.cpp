//
//  main.cpp
//  heap
//
//  Created by John Liao on 1/6/16.
//  Copyright © 2016 John Liao. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class BinaryMinHeap {
private:
    int *data;
    int heapSize;
    int arraySize;
    
public:
    BinaryMinHeap(int size) {
        data = new int[size];
        heapSize = 0;
        arraySize = size;
    }
    
    int getLeftChild(int index) {
        return 2 * index + 1;
    }
    
    int getRightChild(int index) {
        return 2 * index + 2;
    }
    
    int getParent(int index) {
        return (index-2)/2;
    }
    
    int getMin() {
        if (isEmpty()) {
            throw string("Heap is empty");
        }
        return data[0];
    }
    
    bool isEmpty() {
        return (heapSize==0);
    }
    
    void siftUp(int nodeIndex) {
        if (nodeIndex != 0) {
            int parentIndex = getParent(nodeIndex);
            
            if (data[nodeIndex] < data[parentIndex]) {
                int temp = data[parentIndex];
                data[parentIndex] = data[nodeIndex];
                data[nodeIndex] = temp;
                
                siftUp(parentIndex);
            }
        }
    }
    
    void deleteMin() {
        if (heapSize == 0) {
            throw string("Heap empty");
        }
        else {
            data[0] = data[heapSize-1];
            heapSize--;
            siftDown(0);
        }
    }
    
    void siftDown(int nodeIndex) {
        int leftChildIndex = getLeftChild(nodeIndex);
        int rightChildIndex = getRightChild(nodeIndex);
        int minIndex = -1;
        int tmp = -1;
        
        // Disqualify leaf nodes
        if (leftChildIndex >= heapSize) {
            return;
        }
        
        if (rightChildIndex >= heapSize) {
            return;
        }
        
        // Find minimum of children
        if (data[leftChildIndex] < data[rightChildIndex]) {
            minIndex = leftChildIndex;
        }
        else {
            minIndex = rightChildIndex;
        }
        
        // Check if parent breaks heap property
        if (data[nodeIndex] > data[minIndex]) {
            tmp = data[minIndex];
            data[minIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            siftDown(minIndex);
        }
        
    }
    
    void print() {
        for (int k = 0; k < heapSize; k++) {
            cout << data[k] << " ";
        }
        cout << endl;
    }
    
    void insert(int v) {
        if (heapSize==arraySize) {
            throw string("Overflow!");
        }
        else {
            heapSize++;
            data[heapSize-1] = v;
            siftUp(heapSize-1);
        }
    }
    
    ~BinaryMinHeap() {
        delete[] data;
    }

};

int main(int argc, const char * argv[]) {
    BinaryMinHeap H(100);
    
    H.insert(1);
    H.insert(3);
    H.insert(6);
    H.insert(5);
    H.insert(9);
    H.insert(8);
    
    H.print();
    
    H.deleteMin();
    
    H.print();
    
    return 0;
}
