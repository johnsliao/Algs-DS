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

class Stack {
public:
    void peek(); // check rear val
    void pop(); // remove rear val
    void push(int val); // push val into stack
    void print(); // print all vals in stack
private:
    Node *tail = nullptr; // tail = rear
};

#endif /* LinkedList_hpp */
