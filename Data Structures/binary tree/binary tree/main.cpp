//
//  main.cpp
//  binary tree
//
//  Created by John Liao on 12/13/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>

#include "Tree.hpp"
#include "Node.hpp"

int main(int argc, const char * argv[]) {
    Tree T;
    
    T.add(5);
    T.add(6);
    T.add(3);
    T.add(1);
    
    
    T.print(T.getRoot());
    
    T.search(3, T.getRoot());
    
    return 0;
}
