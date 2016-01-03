#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Node.hpp"

using namespace std;

struct Graph {
    typedef vector<Node*> Vmap;
    Vmap vmap;
    
    void add_vector(Node *v) {
        vmap.push_back(v);
    }
    
    void print_vectors() {
        for(Vmap::iterator i = vmap.begin(); i!=vmap.end();i++) {
            cout << (*i)->getVal() << endl;
        }
    }
    
    void link(char from, char to) {
        Node *from_node = nullptr;
        Node *to_node = nullptr;
        
        bool found_from = false;
        bool found_to = false;
        
        for(Vmap::iterator i = vmap.begin(); i!=vmap.end(); i++) {
            if((*i)->getVal()==from) { // found from Node in list
                from_node = *i;
                found_from = true;
            }
            if((*i)->getVal()==to) { // found from Node in list
                to_node = *i;
                found_to = true;
            }
        }
        
        if (found_from && found_to) { // add link to both nodes as an undirected graph
            cout << "Found both. Connecting "<< from << " to " << to << "..." << endl;
            from_node->adj.push_back(to_node);
            to_node->adj.push_back(from_node);
        }
        else {
            cout << "Did not find "<< from << " and " << to << "." << endl;
        }
    }
    
    void printAdj(char val) {
        for(Vmap::iterator i = vmap.begin(); i!=vmap.end(); i++) {
            if((*i)->getVal()==val) { // found from Node in list
                (*i)->printAdj();
                return;
            }
        }
        cout << "Could not find " << val << " in graph." << endl;
    }
    
};

#endif /* Graph_hpp */
