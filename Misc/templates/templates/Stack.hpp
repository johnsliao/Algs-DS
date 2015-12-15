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
#include <iostream>
#include "Node.hpp"

template <typename Y>
class Stack {
public:
    void peek(); // check rear val
    void pop(); // remove rear val
    void push(Y val); // push val into stack
    void print(); // print all vals in stack
private:
    Node<Y> *tail = nullptr; // tail = rear
};

template <typename Y>
void Stack<Y>::peek() {
    std::cout << tail->getVal();
}

template <typename Y>
void Stack<Y>::pop() {
    if (tail == nullptr) {
        std::cout << "Nothing in the Stack" << std::endl;
        return;
    }
    
    Node<Y> *temp = tail;
    delete tail;
    tail = temp->getNext();
}

template <typename Y>
void Stack<Y>::push(Y val) {
    Node <Y>*temp = new Node<Y>(val);
    temp->setNext(tail);
    tail = temp;
}

template <typename Y>
void Stack<Y>::print() {
    Node<Y> *temp = tail;
    
    while(temp!=nullptr) {
        std::cout << temp->getVal() << " ";
        temp=temp->getNext();
    }
    
    std::cout << std::endl;
}

#endif /* LinkedList_hpp */