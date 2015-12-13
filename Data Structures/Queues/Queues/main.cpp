//
//  main.cpp
//  stacks
//
//  Created by John Liao on 12/12/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>
#include "Node.hpp"
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    Queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    q.print();
    
    q.dequeue();
    
    q.print();
    
    q.enqueue(6);
    
    q.print();
    
    return 0;
}
