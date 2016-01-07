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
    
    void print() {
        for (int k = 0; k < heapSize; k++) {
            cout << data[k] << " ";
        }
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
    H.insert(-2);
    
    H.print();
    
    return 0;
}
