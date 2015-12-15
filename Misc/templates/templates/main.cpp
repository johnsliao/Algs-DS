//
//  main.cpp
//  templates
//
//  Created by John Liao on 12/13/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

// Stacks ADT using templates

#include <iostream>
#include "Stack.hpp"
#include "Node.hpp"

int main() {
    Stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    s.print();
    
    s.peek();
    
    return 0;
}