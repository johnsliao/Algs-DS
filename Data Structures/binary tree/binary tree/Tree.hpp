//
//  Tree.hpp
//  binary tree
//
//  Created by John Liao on 12/13/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Node.hpp"

class Tree {
public:
    void add(int val);
    void print(Node *temp);
    void search(int val, Node *temp);
    void del(int val);
    Node *getRoot();
private:
    Node *root = nullptr;
};

#endif /* Tree_hpp */
