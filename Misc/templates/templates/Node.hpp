//
//  Node.hpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <class T>
class Node {
public:
    Node(T val);
    T getVal();
    void setVal(T val);
    Node *getNext();
    void setNext(Node *next);
    
private:
    T val;
    Node *next = nullptr;
};

template <class T>
Node<T>::Node(T val) {
    this->val = val;
}

template <class T>
T Node<T>::getVal() {
    return val;
}

template <class T>
void Node<T>::setVal(T val) {
    this->val = val;
}

template <class T>
void Node<T>::setNext(Node *next) {
    this->next = next;
}

template <class T>
Node <T>*Node<T>::getNext() {
    return next;
}

#endif /* Node_hpp */