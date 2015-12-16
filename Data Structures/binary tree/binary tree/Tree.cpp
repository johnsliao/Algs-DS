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
    //std::cout << temp->getVal() << std::endl; // pre-order traversal
    print(temp->getLeft());
    //std::cout << temp->getVal() << std::endl; // in-order traversal
    print(temp->getRight());
    std::cout << temp->getVal() << std::endl; // post-order traversal
    
}

/*Node *Tree::search(int val) { // iterative
    Node *temp = root;
    
    while (temp!=nullptr) {
        if (temp->getVal()==val)
            return temp;
        else if (val<temp->getVal())
            temp=temp->getLeft();
        else
            temp=temp->getRight();
    }
    
    return temp;
}*/

Node *Tree::search(int val, Node *temp) { // recursive
    if (temp == nullptr || temp->getVal() == val)
        return temp;
    else if (val<temp->getVal())
        return search(val, temp->getLeft());
    else
        return search(val, temp->getRight());
}

void Tree::del(int val, Node *node, Node *parent) {
    if (val<node->getVal())
        del(val,node->getLeft(), node);
    else if (val>node->getVal())
        del(val,node->getRight(), node);
    else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) { // no children
            if (parent->getRight() == node)
                parent->setRight(nullptr);
            else
                parent->setLeft(nullptr);
            
            delete node;
        }
        else if (node->getLeft() == nullptr) { // left only
            
        }
        else if (node->getRight() == nullptr) { // right only
            
        }
        else { //two children
            
        }
    }
    
}

int Tree::countNodes(Node *node) {
    if (node==nullptr)
        return 0;
    else
        return 1+countNodes(node->getLeft())+countNodes(node->getRight());
    
}

bool Tree::isBST(int minKey, int maxKey, Node *node) {
    if (node == nullptr)
        return true;
    if (node->getVal()<minKey || node->getVal()>maxKey)
        return false;
    return isBST(minKey, node->getVal(), node->getLeft()) && isBST(node->getVal(), maxKey, node->getRight());
}