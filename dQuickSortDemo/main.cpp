//
//  main.cpp
//  dQuickSortDemo
//
//  Created by Kevin Zhang on 2016-06-18.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//


#include <iostream>
#include <fstream>
#include "dquick.hpp"

using namespace std;

// you'll have to adjust this number as required
#define ARR_LEN 50000
int A[ARR_LEN];

void createArraytoFile(int* A, int arrayLength);

int main(int argc, const char * argv[]) {
    //create test array here
    for (int i =0; i<ARR_LEN ; i++) {
        A[i] = i+1;
    }
    
    //generate array to file
    createArraytoFile(A, ARR_LEN);
    
//    for (int i = 0; i < ARR_LEN; i++) {
//        cin >> A[i];
//    }
    
    dquicksort(A, ARR_LEN);
    
    
    //sorting check
    for (int i = 1; i < ARR_LEN; i++) {
        if (A[i-1] > A[i]) cout << "bad";
    }
    
    /*
     for (int i = 0; i < ARR_LEN; i++) {
     cout << A[i] << ' ';
     }
     cout << '\n';
     */

    cout << "Hello, World!\n";
    return 0;
}

void createArraytoFile(int* A, int arrayLength){
    //take the input array
    //output to text file
    fstream outfile("worstRunningTime.txt", fstream::out);
    for (int i =0; i<arrayLength; ++i) {
        outfile << A[i] << endl;
    }
    
    outfile.close();
}
