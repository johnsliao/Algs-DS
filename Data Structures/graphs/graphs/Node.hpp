#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char val;
    typedef vector<Node*> adj_list;
    adj_list adj;
    bool seen=false;
    
    Node(char val) {
        this->val=val;
    }
    char getVal() {
        return val;
    }
    void printAdj() {
        for (adj_list::iterator itr = adj.begin(); itr !=adj.end(); itr++) {
            cout << (*itr)->getVal() << " ";
        }
        cout << endl;
    }
};

#endif /* Node_hpp */
