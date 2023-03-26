#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "printVec.h"
#include <vector>
using std::vector;

// Helper function for heapSort
inline int leftChild(int i) {
    return 2 * i + 1;
}

// Helper function for heapSort
// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(vector<Comparable> &items, int& i, unsigned long& n, int& child, Comparable& tmp, int& reads, int& writes) {
    for(tmp = items[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        // choose the child with the larger value
        if (child != n - 1 && items[child] < items[child + 1]) {
            ++child;
        }
        reads += 2;
        // if the parent is less than the child, swap them
        reads += 2; // Pre-emptive
        if (tmp < items[child]) {
            items[i] = items[child];
            reads++;
            writes++;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    reads++;
    writes++;
    items[i] = tmp;
    reads++;
    writes++;
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items, int& reads, int& writes) {
    reads = 0;
    writes = 0;
    int i, child;
    Comparable temp, tmp;
    unsigned long j, n;
    // build the heap (with max value at root)
    for (i = items.size() / 2 - 1; i >= 0; --i) {
        n = items.size();
        percolateDown(items, i, n, child, tmp, reads, writes);
    }
//    printVec(items);
    // keep deleting the max
    for (j = items.size() - 1; j > 0; --j) {
        // swap the maximum out
        temp = items[0];
        reads++;
        writes++;
        items[0] = items[j];
        reads++;
        writes++;
        items[j] = temp;
        reads++;
        writes++;

        // make it into a heap again
        i = 0;
        percolateDown(items, i, j, child, tmp, reads, writes);

//        printVec(items);
    }
    return items;
}

#endif
