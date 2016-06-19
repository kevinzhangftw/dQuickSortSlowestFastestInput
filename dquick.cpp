//
//  dquick.cpp
//  dQuickSortDemo
//
//  Created by Kevin Zhang on 2016-06-18.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "dquick.hpp"

int dpartition(int* A, int len);  // prototype


int dpartition(int* A, int len) {
    int i = 0;
    int x = A[0];
    int tmp;
    for (int j = 1; j < len; j++) {
        if (A[j] <= x) {
            i += 1;
            tmp = A[i]; A[i] = A[j]; A[j] = tmp;  // Exchange
        }
    }
    tmp = A[i]; A[i] = A[0]; A[0] = tmp;  // Exchange
    return i;
} // dpartition


void dquicksort(int* A, int len) {
    if (len < 2) return;
    int q = dpartition(A, len);
    dquicksort(A, q);
    dquicksort(A+(q+1), len-(q+1));
} // dquicksort
