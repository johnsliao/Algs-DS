//
//  main.cpp
//  hash tables with chaining with linked lists
//
//  Created by John Liao on 12/10/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>

class Node {
public:
    Node() {val = 0; next = nullptr;}
    int getVal() {return val;}
    void setVal(int _val) {val = _val;}
    void setNext(Node * _next) {next=_next;}
    Node* getNext() {return next;}
    
private:
    int val;
    Node* next;
};

class LinkedList {
public:
    LinkedList(){};
    void insert(int val);
    bool find(int val);
    
private:
        Node * head;
};

void LinkedList::insert(int val) {
    Node * temp;
    
    if(head==nullptr) {
        head = new Node();
        head->setVal(val);
        return;
    }
    
    temp = head;
    
    while(temp->getNext()!=nullptr) {
        temp=temp->getNext();
    }
    
    Node * temp2 = new Node();
    temp2->setVal(val);
    temp->setNext(temp2);

    return;

}

bool LinkedList::find(int val) {
    Node * temp = head;
    
    while(temp!=nullptr) {
        if (val == temp->getVal())
            return true;
        
        temp=temp->getNext();
    }
    return false;
}

int hash(int _key, int _size) { // size of hash table
    return _key%_size; // simple hash function
}

int main(int argc, const char * argv[]) {
    const int size = 100;
    
    int key = 232;
    
    int someVal = 9001;
    int someVal2 = 9002;
    
    LinkedList hashTable[size];
    
    hashTable[hash(key,size)].insert(someVal); // insert some values into the hash table!
    hashTable[hash(key,size)].insert(someVal2); // insert some values into the hash table!
    
    if (hashTable[32].find(someVal2)) // check to see if chaining properly handled collision
        std::cout << "We found it!" << std::endl;
    else
        std::cout << "We didn't find it!" << std::endl;
    
    return 0;
}
