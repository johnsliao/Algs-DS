#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

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
        Vmap::iterator from_itr = find_if(vmap.begin(), vmap.end(), [from](Node* node){return node->getVal()==from;});
        Vmap::iterator to_itr = find_if(vmap.begin(), vmap.end(), [to](Node* node){return node->getVal()==to;});

        
        if (from_itr!=vmap.end() && to_itr!=vmap.end()) { // add link to both nodes as an undirected graph
            cout << "Found both. Connecting "<< from << " to " << to << "..." << endl;
            (*from_itr)->adj.push_back(*to_itr);
            (*to_itr)->adj.push_back(*from_itr);
        }
        else {
            cout << "Did not find "<< from << " and " << to << "." << endl;
        }
    }
    
    void printAdj(char val) {
        Vmap::iterator itr = find_if(vmap.begin(), vmap.end(), [val](Node* node){return node->getVal()==val;});
        
        if(itr!=vmap.end()) {
            (*itr)->printAdj();
            return;
        }
        
        cout << "Could not find " << val << " in graph." << endl;
    }
    
    // DFS Iterative
    void DFS_iterative() {
        stack<Node*> path;
        vector<Node*> seen;
        
        Node::adj_list::iterator adj_itr;
        
        path.push(vmap.front());
        seen.push_back(vmap.front());
        
        cout << vmap.front()->getVal() << " ";
        
        while(!path.empty()) {
            Node * current_node = path.top();
            
            for(adj_itr=current_node->adj.begin(); adj_itr!=current_node->adj.end(); adj_itr++) {
                Vmap::iterator seen_itr = find(seen.begin(), seen.end(), *adj_itr); // search adj in seen
                
                if(seen_itr==seen.end()) { // if adj Node not in seen
                    cout << (*adj_itr)->getVal() << " ";
                    path.push(*adj_itr);
                    seen.push_back(*adj_itr); // add to seen
                    break;
                }
            }
            if(adj_itr==current_node->adj.end()) { // if all seen, move back
                path.pop();
            }
        }
        cout << endl;
    }
    
    // DFS Recursive
    
    
    // BFS
    
};

#endif /* Graph_hpp */
