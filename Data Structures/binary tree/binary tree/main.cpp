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
    
    /*// Search
    int searchVal = 4;
    
    if(T.search(searchVal, T.getRoot())==nullptr)
        std::cout << searchVal << " not found" << std::endl;
    else
        std::cout << "Found " << searchVal << std::endl;
    
    // Count Nodes
    std::cout << "There are " << T.countNodes(T.getRoot()) << " nodes" << std::endl;
    

    // isBST?
    if (T.isBST(0,20,T.getRoot()))
        std::cout << "Tree is BST" << std::endl;
    else
        std::cout << "Tree is NOT BST" << std::endl;*/
    
    // Delete
    std::cout << "Delete!" << std::endl;
    T.del(1, T.getRoot(), T.getRoot());
    
    T.print(T.getRoot());
    
    
    return 0;
}
