//
//  main.cpp
//  templates
//
//  Created by John Liao on 12/13/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>

template <typename P>
P compare(P a, P b) {
    if (a>b)
        return a;
    else
        return b;
}

int main() {
    //float a=3.1, b=3.5;
    int a=3, b=4;
    
    std::cout << "Comparing " << a << " and " << b << std::endl;
    std::cout << compare(a,b) << " is greater!" << std:: endl;
    return 0;
}