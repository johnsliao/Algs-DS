//
//  LinkedList.hpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "Node.hpp"

class Queue {
public:
    void enqueue(int val); // add to "tail"
    void dequeue(); // remove head
    void print(); // print from head to tail
private:
    Node *head = nullptr;
};

#endif /* Queue_hpp */
