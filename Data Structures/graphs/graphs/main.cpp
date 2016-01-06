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
    g.add_vector(new Node('q'));
    
    g.link('a','z');
    g.link('z','s');
    g.link('z','x');
    g.link('z','d');
    g.link('a','c');
    g.link('c','f');
    g.link('c','v');
    g.link('c','q');
    
    //g.DFS_iterative(g.vmap.front());
    
    //g.DFS_recursive(g.vmap.front());
    
    g.BFS(g.vmap.front());
    
    return 0;
}
