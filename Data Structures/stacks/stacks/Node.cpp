//
//  Node.cpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include "Node.hpp"

Node::Node(int val) {
    this->val = val;
}

int Node::getVal() {
    return val;
}

void Node::setVal(int val) {
    this->val = val;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node *Node::getNext() {
    return next;
}