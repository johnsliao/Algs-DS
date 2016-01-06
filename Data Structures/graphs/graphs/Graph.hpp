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
    void DFS_iterative(Node * v) {
        stack<Node*> path;
        Node::adj_list::iterator adj_itr;
        Node * current_node = nullptr;
        
        path.push(v);
        
        while(!path.empty()) {
            current_node = path.top();
            path.pop();
            
            if(current_node->seen==false) {
                cout << current_node->getVal() << " ";
                current_node->seen=true;
                
                for(adj_itr=current_node->adj.begin(); adj_itr!=current_node->adj.end(); adj_itr++) {
                    path.push(*adj_itr);
                }
            }
        }
    }
    
    // DFS Recursive
    void DFS_recursive(Node *current_node) {
        Node::adj_list::iterator adj_itr;
        current_node->seen=true;
        
        cout << (current_node)->getVal() << " ";
        
        for(adj_itr=current_node->adj.begin(); adj_itr!=current_node->adj.end(); adj_itr++) {
            if((*adj_itr)->seen==false)  // if adj Node not in seen
                DFS_recursive(*adj_itr);
        }
    }
    
    // BFS
    void BFS(Node *v) {
        cout << "\nBFS: ";
        vector<Node*> path;
        Node::adj_list::iterator adj_itr;
        Node* current_node =nullptr;
    
        path.push_back(v);
        cout << v->getVal() << " ";
        
        while(!path.empty()) {
            current_node = path.front();
            path.erase(path.begin());
            
            for(adj_itr=current_node->adj.begin(); adj_itr!=current_node->adj.end(); adj_itr++) {
                if((*adj_itr)->seen==false) {
                    cout << (*adj_itr)->getVal() << " ";
                    (*adj_itr)->seen=true;
                    path.push_back(*adj_itr);
                }
                
            }

        }
    }
    
};

#endif /* Graph_hpp */
