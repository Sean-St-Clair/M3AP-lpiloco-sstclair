#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "File Input.h"
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main() {
    // Create a new vector of magical trinkets
    vector<Trinket> trinkets;
    // Read CSV data into this vector
    readDataFromFile("ACSV 1.csv", trinkets);
    // Shuffle vector
    shuffle(trinkets.begin(), trinkets.end(), default_random_engine()); // NOLINT(cert-msc51-cpp)

    // Timer variables
    chrono::steady_clock::time_point begin, end;

    int reads, writes;
    int tempReads, tempWrites;
    int size = 1000;
    for (int i = 0; i < 10; ++i) {
        trinkets.resize(size);

        // Bubble sort
        begin = chrono::steady_clock::now();
        bubbleSort(trinkets, reads, writes);
        cout << size << " bubble reads: " << reads << endl;
        cout << size << " bubble writes: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
        cout << endl;

        // Selection
        begin = chrono::steady_clock::now();
        selectionSort(trinkets, reads, writes);
        cout << size << " selection reads: " << reads << endl;

        cout << size << " selection writes: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
        cout << endl;

        // Quick sort unstable
        begin = chrono::steady_clock::now();
        quickSortUnstable(trinkets, reads, writes);
        cout << size << " quick unstable reads: " << reads << endl;
        cout << size << " quick unstable writes: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
        cout << endl;

        // Heap
        begin = chrono::steady_clock::now();
        heapSort(trinkets, reads, writes);
        cout << size << " heap reads: " << reads << endl;
        cout << size << " heap writes: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
        cout << endl;

        // Two-Sort (quick sort stable done twice on different fields)
        begin = chrono::steady_clock::now();
        vector<Trinket> firstSort = quickSortStable(trinkets, reads, writes, true);
        tempReads = reads;
        tempWrites = writes;
        cout << "Two sort:" << endl;
        cout << size << " first stable quick sort reads: " << reads << endl;
        cout << size << " first stable quick sort writes: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
        cout << endl;

        begin = chrono::steady_clock::now();
        quickSortStable(firstSort, reads, writes, false);
        reads += tempReads;
        writes += tempWrites;
        cout << size << " second stable quick sort reads: " << reads << endl;
        cout << size << " second stable quick sort reads: " << writes << endl;
        end = chrono::steady_clock::now();
        cout << "Elapsed time = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;

        cout << "------------------------" << endl;

        // Decrement size
        size -= 100;
    }

    // TODO: Add another sorting algorithm (kinda already did?)
    // TODO: repeat experiment except double size each time (new main)

    return 0;
}