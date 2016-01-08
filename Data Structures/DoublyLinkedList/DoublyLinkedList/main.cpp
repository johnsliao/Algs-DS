//
//  main.cpp
//  DoublyLinkedList
//
//  Created by John Liao on 1/7/16.
//  Copyright © 2016 John Liao. All rights reserved.
//

#include <iostream>
#include <string>

class Node {
private:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }

    int getVal() {return data;}
    
    Node *getPrev() {return prev;}
    Node *getNext() {return next;}
    
    void setPrev(Node *node) {prev = node;}
    void setNext(Node *node) {next = node;}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
    
public:
    DoublyLinkedList () {
        head = nullptr;
        tail = nullptr;
    }
    
    Node *findNode(int data) {
        Node * itr = nullptr;
        
        if (head == nullptr && tail == nullptr)
            return nullptr;
        
        for (itr = head; itr != nullptr; itr = itr->getNext()) {
            if (itr->getVal() == data) {
                return itr;
            }
        }
        
        return nullptr;
    }
    
    void insertAfter(Node *node, Node *newNode) {

        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
            
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
            return;
        }
        
        if (node == nullptr) {
            std::cout << "Insert-After node not found" << std::endl;
            return;
        }
        
        newNode->setPrev(node);
        newNode->setNext(node->getNext());

        if (newNode->getNext() == nullptr) {
            tail = newNode;
        }
        else {
            node->getNext()->setPrev(newNode);
        }
        
        node->setNext(newNode);
    }
    
    void insertBefore(Node *node, Node *newNode) {
        insertAfter(node->getPrev(), newNode);
    }
    
    void printForward() {
        Node *itr = nullptr;
        
        for (itr = head; itr != nullptr; itr=itr->getNext()) {
            std::cout << itr->getVal() << " ";
        }
        std::cout << std::endl;
    }
    
    void printBackward() {
        Node *itr = nullptr;
        
        for (itr = tail; itr != nullptr; itr=itr->getPrev()) {
            std::cout << itr->getVal() << " ";
        }
        std::cout << std::endl;
    }
    
    void remove(Node *node) {
        if (node==nullptr) {
            std::cout << "Node not found" << std::endl;
            return;
        }
        
        else if (node == head) {
            head = head->getNext();
            head->setPrev(nullptr);
            delete node;
        }
        
        else if (node == tail) {
            tail = tail->getPrev();
            tail->setNext(nullptr);
            delete node;
        }
        
        else {
            Node *previousToNode = node->getPrev();
            Node *nextToNode = node->getNext();
            
            previousToNode->setNext(nextToNode);
            nextToNode->setPrev(previousToNode);
            
            delete node;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    DoublyLinkedList DLL;
    
    DLL.insertAfter(nullptr, new Node(1));
    DLL.insertAfter(DLL.findNode(1), new Node(2));
    DLL.insertAfter(DLL.findNode(2), new Node(3));
    DLL.insertAfter(DLL.findNode(3), new Node(4));
    DLL.insertAfter(DLL.findNode(4), new Node(5));
    DLL.insertAfter(DLL.findNode(5), new Node(6));
    
    DLL.insertBefore(DLL.findNode(5), new Node(72));
    
    DLL.printForward();
    DLL.printBackward();
    
    DLL.remove(DLL.findNode(72));
    
    DLL.printForward();
    DLL.printBackward();
    
    return 0;
}
