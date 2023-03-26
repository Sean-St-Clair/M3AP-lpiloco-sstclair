#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"
#include "fileInput.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex, int &reads, int &writes) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[startIndex];
    reads++;
    writes++;

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    int i;
    int largerElementIndex = startIndex + 1;
    Comparable temp;
    for (i = startIndex + 1; i <= endIndex; ++i) {
        // TODO: Don't be hasty. -Treebeard
        // TODO: LOOK at every thing like "partition" not just vec[0]
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i];
            reads++;
            writes++;
            vec[i] = vec[largerElementIndex];
            reads++;
            writes++;
            vec[largerElementIndex] = temp;
            reads++;
            writes++;
            // Update largerElementIndex
            ++largerElementIndex;
        }
        reads += 2;
    }
    // Swap the partition element into place
    temp = vec[startIndex];
    reads++;
    writes++;
    vec[startIndex] = vec[largerElementIndex - 1];
    reads++;
    writes++;
    vec[largerElementIndex - 1] = temp;
    reads++;
    writes++;

//    printVec(vec);

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex - 2, reads, writes);
    quickSortUnstableRec(vec, largerElementIndex, endIndex, reads, writes);
}

template<typename Comparable>
void quickSortUnstable(vector<Comparable> vec, int &reads, int &writes) {
    reads = 0;
    writes = 0;
    quickSortUnstableRec(vec, 0, vec.size() - 1, reads, writes);
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, int &reads, int &writes) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    reads++;
    writes++;

    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        reads += 2;
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            reads++;
            writes++;
        } else if (vec[i] > partition) {
            reads += 2;
            larger.push_back(vec[i]);
            reads++;
            writes++;
        } else {
            reads += 2;
            equal.push_back(vec[i]);
            reads++;
            writes++;
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, writes);
    quickSortStableRec(larger, reads, writes);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            reads++;
            writes++;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            reads++;
            writes++;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            reads++;
            writes++;
        }
    }

//    printVec(vec);
}

void quickSortStableRecModifier(vector<Trinket> &vec, int &reads, int &writes) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Trinket partition = vec[0];
    reads++;
    writes++;

    vector<Trinket> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        reads += 2;
        if (vec[i].getModifier() < partition.getModifier()) {
            smaller.push_back(vec[i]);
            reads++;
            writes++;
        } else if (vec[i].getModifier() > partition.getModifier()) {
            reads += 2;
            larger.push_back(vec[i]);
            reads++;
            writes++;
        } else {
            reads += 2;
            equal.push_back(vec[i]);
            reads++;
            writes++;
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, writes);
    quickSortStableRec(larger, reads, writes);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            reads++;
            writes++;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            reads++;
            writes++;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            reads++;
            writes++;
        }
    }

//    printVec(vec);
}

vector<Trinket> quickSortStable(vector<Trinket> vec, int &reads, int &writes, bool usingOwner) {
    reads = 0;
    writes = 0;
    if (usingOwner)
        quickSortStableRec(vec, reads, writes);
    else // Using "Modifier" field
        quickSortStableRecModifier(vec, reads, writes);
    return vec;
}

#endif
