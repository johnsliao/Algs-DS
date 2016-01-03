//
//  vertex.hpp
//  Graphs
//
//  Created by John Liao on 12/29/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef vertex_hpp
#define vertex_hpp

#include <stdio.h>
#include <vector>

using namespace std;
struct Vertex {
    vector<Vertex*> adj;
    char name;
    Vertex(char s) {name=s;}
};

#endif /* vertex_hpp */
