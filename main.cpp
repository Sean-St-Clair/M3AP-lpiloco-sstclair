#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "fileInput.h"
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
    // Records reads and writes data for sizes ranging from 1,000 to 100
    for (int i = 0; i < 10; ++i) {
        trinkets.resize(size);

        // Bubble sort
        bubbleSort(trinkets, reads, writes);
        bubbleOut << size << " reads " << reads << endl;
        bubbleOut << size << " writes " << writes << endl;

        // Selection
        selectionSort(trinkets, reads, writes);
        selectionOut << size << " reads " << reads << endl;
        selectionOut << size << " writes " << writes << endl;

        // Quick sort unstable
        quickSortUnstable(trinkets, reads, writes);
        quickOut << size << " reads " << reads << endl;
        quickOut << size << " writes " << writes << endl;

        // Heap
        heapSort(trinkets, reads, writes);
        heapOut << size << " reads " << reads << endl;
        heapOut << size << " writes " << writes << endl;

        // Two-Sort (quick sort stable done twice on different fields)
        vector<Trinket> firstSort = quickSortStable(trinkets, reads, writes, true);
        tempReads = reads;
        tempWrites = writes;
        firstTwoOut << size << " reads " << reads << endl;
        firstTwoOut << size << " writes " << writes << endl;

        quickSortStable(firstSort, reads, writes, false);
        reads += tempReads;
        writes += tempWrites;
        secondTwoOut << size << " reads " << reads << endl;
        secondTwoOut << size << " writes " << writes << endl;

        // Decrement size
        size -= 100;
    }

    // Closing the output files
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