#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
void bubbleSort(vector<Comparable> vec, int& reads, int& writes) {
    reads = 0;
    writes = 0;
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            // TODO: Remember that equals is writing stuff sometimes
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                reads++;
                writes++;
                vec[i] = vec[i+1];
                reads++;
                writes++;
                vec[i+1] = temp;
                reads++;
                writes++;
                // Update haveSwapped
                haveSwapped = true;
            }
            reads += 2;
            // TODO: Remember to count stuff outside of brackets
        }
        // Update numPasses
        ++numPasses;
//        printVec(vec);
    }
}

#endif
