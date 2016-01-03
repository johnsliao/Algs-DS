//
//  main.cpp
//  graphs
//
//  Created by John Liao on 12/30/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include "Graph.hpp"
#include "Node.hpp"

int main(int argc, const char * argv[]) {
    Graph g;
    
    g.add_vector(new Node('a'));
    g.add_vector(new Node('z'));
    g.add_vector(new Node('s'));
    g.add_vector(new Node('x'));
    g.add_vector(new Node('d'));
    g.add_vector(new Node('c'));
    g.add_vector(new Node('f'));
    g.add_vector(new Node('v'));
    
    g.print_vectors();
    
    g.link('a','z');
    g.link('a','s');
    g.link('x','d');
    g.link('x','c');
    g.link('d','c');
    g.link('d','f');
    g.link('c','f');
    g.link('f','v');
    g.link('c','v');
    
    g.printAdj('a');
    
    return 0;
}
