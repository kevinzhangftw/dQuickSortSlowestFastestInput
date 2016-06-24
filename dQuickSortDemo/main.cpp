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
#include <math.h>
using namespace std::chrono;

using namespace std;

// you'll have to adjust this number as required
#define ARR_LEN 100000
//#define ARR_LEN 10000000
//#define ARR_LEN 7
int A[ARR_LEN];

void createArraytoFile(int* A, int arrayLength);
void swappingPivots(int* A, int arrayLength);

int main(int argc, const char * argv[]) {
    //Worst case
//    for (int i =0; i<ARR_LEN ; i++) {
//        A[i] = 0;
//    }
//
    //Best case
        for (int i =0; i<ARR_LEN ; i++) {
            A[i] = i+1;
        }
//    cout << "BEFORE SWAPPING" << endl;
//    //print out the array
//    for (int i = 0;  i<ARR_LEN; ++i) {
//        cout << A[i];
//    }
    //pivot is as close to center as possible
    swappingPivots(A, ARR_LEN);
    
//    cout << "AFTER SWAPPING" << endl;
//    //print out the array
//    for (int i = 0;  i<ARR_LEN; ++i) {
//        cout << A[i];
//    }
    
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
//    //output worst
//    fstream outfile("qs-worst.in", fstream::out);
//    for (int i =0; i<arrayLength; ++i) {
//        outfile << A[i] << endl;
//    }
//    
//    outfile.close();
    
    //output best
    fstream outfile("qs-best.in", fstream::out);
    for (int i =0; i<arrayLength; ++i) {
        outfile << A[i] << endl;
    }
    
    outfile.close();
}

void swappingPivots(int* A, int arrayLength){
    if (arrayLength < 2) return;
    //swap a[0] and a[arraylength/2]
    int tmp = A[0]; A[0] = A[int(floor(arrayLength/2))] ; A[int(floor(arrayLength/2))] = tmp;
    //call swappingpivots on left subarray
    swappingPivots(A, arrayLength/2);
    //call swappingpivots on right subarray
    swappingPivots(A, arrayLength- int(floor(arrayLength/2)));
}