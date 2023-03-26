#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "File Input.h"
#include <algorithm>
#include <random>

using namespace std;

int main() {
    // Create a new vector of magical trinkets
    vector<Trinket> trinkets;
    // Read CSV data into this vector
    readDataFromFile("ACSV 1.csv", trinkets);
    // Shuffle vector
    shuffle(trinkets.begin(), trinkets.end(), default_random_engine()); // NOLINT(cert-msc51-cpp)

    // Setting up file output for each graph
    ofstream bubbleOut, selectionOut, quickOut, heapOut, firstTwoOut, secondTwoOut;
    bubbleOut.open("../data/bubbleData.txt");
    selectionOut.open("../data/selectionData.txt");
    quickOut.open("../data/quickData.txt");
    heapOut.open("../data/heapData.txt");
    firstTwoOut.open("../data/firstTwoSortData.txt");
    secondTwoOut.open("../data/secondTwoSortData.txt");

    int reads, writes;
    int tempReads, tempWrites;
    int size = 1000;
    for (int i = 0; i < 10; ++i) {
        trinkets.resize(size);

        // Bubble sort
        bubbleSort(trinkets, reads, writes);
        bubbleOut << size << " bubble reads: " << reads << endl;
        bubbleOut << size << " bubble writes: " << writes << endl;

        // Selection
        selectionSort(trinkets, reads, writes);
        selectionOut << size << " selection reads: " << reads << endl;
        selectionOut << size << " selection writes: " << writes << endl;

        // Quick sort unstable
        quickSortUnstable(trinkets, reads, writes);
        quickOut << size << " quick unstable reads: " << reads << endl;
        quickOut << size << " quick unstable writes: " << writes << endl;

        // Heap
        heapSort(trinkets, reads, writes);
        heapOut << size << " heap reads: " << reads << endl;
        heapOut << size << " heap writes: " << writes << endl;

        // Two-Sort (quick sort stable done twice on different fields)
        vector<Trinket> firstSort = quickSortStable(trinkets, reads, writes, true);
        tempReads = reads;
        tempWrites = writes;
        firstTwoOut << size << " first stable quick sort reads: " << reads << endl;
        firstTwoOut << size << " first stable quick sort writes: " << writes << endl;

        quickSortStable(firstSort, reads, writes, false);
        reads += tempReads;
        writes += tempWrites;
        secondTwoOut << size << " second stable quick sort reads: " << reads << endl;
        secondTwoOut << size << " second stable quick sort reads: " << writes << endl;

        // Decrement size
        size -= 100;
    }

    bubbleOut.close();
    selectionOut.close();
    quickOut.close();
    heapOut.close();
    firstTwoOut.close();
    secondTwoOut.close();

    // Command line call Python file
    string command = "python ../sortingGraphs.py";
    system(command.c_str());

    return 0;
}