//
//  Tree.cpp
//  binary tree
//
//  Created by John Liao on 12/13/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"

Node *Tree::getRoot() {
    return root;
}

void Tree::add(int val) {
    
    if (root==nullptr) {
        root = new Node(val);
        return;
    }
    
    Node * temp = root;
    
    bool added = false;
    
    // assumes no children node val equal to parent
    // iterative solution
    while(!added) {
        // Check with current val, if < go left; if > go right
        if (val<temp->getVal()) {
            if (temp->getLeft()!=nullptr) {
                temp = temp->getLeft();
            }
            else { // found leaf
                temp->setLeft(new Node(val));
                added=true;
            }
        }
        else if (val>temp->getVal()) {
            if (temp->getLeft()!=nullptr) {
                temp = temp->getRight();
            }
            else {
                temp->setRight(new Node(val));
                added=true;
            }
        }
    }
}

void Tree::print(Node *temp) { // recursive print
    if (temp==nullptr) { // root is null
        return;
    }
    
    std::cout << temp->getVal() << std::endl;
    
    print(temp->getLeft());
    print(temp->getRight());
}

void Tree::search(int val, Node *temp) {
    if (temp==nullptr)
        return;
    
    if (val==temp->getVal())
        std::cout << "Found " << val << std::endl;
    
    search(val,temp->getLeft());
    search(val,temp->getRight());
    
}

void Tree::del(int val) {
    // to be implemented
}