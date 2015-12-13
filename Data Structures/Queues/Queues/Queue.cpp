//
//  LinkedList.cpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include "Queue.hpp"
#include <iostream>

void Queue::enqueue(int val) {
    Node *temp = new Node(val);
    
    if (temp==nullptr) {
        std::cout << "Not enough memory!" << std::endl;
        return;
    }
    
    if (head==nullptr) {
        head = temp;
        return;
    }
    
    Node *traverseNode = head;
    
    while (traverseNode->getNext()!=nullptr) {
        traverseNode = traverseNode->getNext();
    }
    
    traverseNode->setNext(temp);
}

void Queue::dequeue() {
    if (head == nullptr) {
        std::cout << "Nothing in queue!" << std::endl;
        return;
    }
    
    Node *temp = head;
    delete head;
    head = temp->getNext();
}

void Queue::print() {
    Node *temp = head;
    
    while(temp!=nullptr) {
        std::cout << temp->getVal() << " ";
        temp=temp->getNext();
    }
    
    std::cout << std::endl;
}