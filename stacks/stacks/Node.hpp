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

class Node {
public:
    Node(int val);
    int getVal();
    void setVal(int val);
    Node *getNext();
    void setNext(Node *next);
    
private:
    int val;
    Node *next = nullptr;
};

#endif /* Node_hpp */
