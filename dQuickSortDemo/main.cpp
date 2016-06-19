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
#include <chrono>
using namespace std::chrono;

using namespace std;

// you'll have to adjust this number as required
//#define ARR_LEN 50000
#define ARR_LEN 10000000
int A[ARR_LEN];

void createArraytoFile(int* A, int arrayLength);

int main(int argc, const char * argv[]) {
    //Worst case
//    for (int i =0; i<ARR_LEN ; i++) {
//        A[i] = 0;
//    }
//
    //Best case
        for (int i =0; i<ARR_LEN ; i++) {
            A[i] = i+1;
            //pivot is as close to center as possible
            
        }
    
    //generate array to file
    createArraytoFile(A, ARR_LEN);
    
//    for (int i = 0; i < ARR_LEN; i++) {
//        cin >> A[i];
//    }
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    dquicksort(A, ARR_LEN);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << duration << endl;
    
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
    return 0;
}

void createArraytoFile(int* A, int arrayLength){
    //take the input array
    //output to text file
    fstream outfile("qs-worst.in", fstream::out);
    for (int i =0; i<arrayLength; ++i) {
        outfile << A[i] << endl;
    }
    
    outfile.close();
}
