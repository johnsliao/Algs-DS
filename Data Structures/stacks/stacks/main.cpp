//
//  main.cpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>
#include "Node.hpp"
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    s.print();
    
    s.pop();
    
    s.print();
    
    s.peek();
    
    return 0;
}
