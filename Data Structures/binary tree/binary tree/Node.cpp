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

void Node::setRight(Node *right) {
    this->right = right;
}

void Node::setLeft(Node *left) {
    this->left = left;
}

Node *Node::getRight() {
    return right;
}

Node *Node::getLeft() {
    return left;
}

