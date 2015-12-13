//
//  LinkedList.cpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include "Stack.hpp"
#include <iostream>

void Stack::peek() {
    std::cout << tail->getVal();
}

void Stack::pop() {
    if (tail == nullptr) {
        std::cout << "Nothing in the Stack" << std::endl;
        return;
    }
    
    Node *temp = tail;
    delete tail;
    tail = temp->getNext();
}

void Stack::push(int val) {
    Node *temp = new Node(val);
    temp->setNext(tail);
    tail = temp;
}

void Stack::print() {
    Node *temp = tail;
    
    while(temp!=nullptr) {
        std::cout << temp->getVal() << " ";
        temp=temp->getNext();
    }
    
    std::cout << std::endl;
}