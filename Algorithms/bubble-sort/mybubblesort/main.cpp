//
//  main.cpp
//  mybubblesort
//
//  Created by John Liao on 10/17/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int arr[10] = {500, 2, 1, 9, -1, 14, -300, 23, 8, 5};
    int length = 10;
    
    bool done = true;
    
    for (int a = 0; a < length; a++)
        cout << arr[a] << " ";
    
    cout << endl;

    do {
        done = true;
        for (int x = 0; x < length; x++)
        {
            if ( arr[x] > arr[x+1] )
            { // need to swap
                done = false;
                int t = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = t;
            }
        }
    } while(!done);
    
    for (int a = 0; a < length; a++)
        cout << arr[a] << " ";
    
    
    return 0;
}

