//
//  main.cpp
//  dQuickSortDemo
//
//  Created by Kevin Zhang on 2016-06-18.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//


#include <iostream>
#include "dquick.hpp"

using namespace std;

// you'll have to adjust this number as required
#define ARR_LEN 15
int A[ARR_LEN];

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int i = 0; i < ARR_LEN; i++) {
        cin >> A[i];
    }
    
    dquicksort(A, ARR_LEN);
    
    for (int i = 1; i < ARR_LEN; i++) {
        if (A[i-1] > A[i]) cout << "bad";
    }
    
    /*
     for (int i = 0; i < ARR_LEN; i++) {
     cout << A[i] << ' ';
     }
     cout << '\n';
     */

    std::cout << "Hello, World!\n";
    return 0;
}
