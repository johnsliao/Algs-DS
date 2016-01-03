//
//  vertex.cpp
//  Graphs
//
//  Created by John Liao on 12/29/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include "vertex.hpp"
#include <iostream>
#include <vector>

std::vector<Vertex*> Vertex::getAdj() {
    return adj;
}

void Vertex::addAdj(Vertex *adjVertex) {
    adj.push_back(adjVertex);
}

void Vertex::printVal() {
    std::cout << "Val is " << val << std::endl;
}