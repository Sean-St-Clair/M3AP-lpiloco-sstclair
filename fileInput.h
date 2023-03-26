//
// Created by Sean St. Clair on 9/28/2022.
//

#ifndef PROJECT_2_FILE_INPUT_H
#define PROJECT_2_FILE_INPUT_H

#include <fstream>
#include <iostream>
#include <vector>
#include <trinket.h>

using std::ifstream;
using std::vector;

// This function reads the data from a CSV file containing information on the magical items,
// and stores each line's values in a Trinket object in a given vector of Trinkets.
void readDataFromFile(string filename, vector<Trinket> &trinkets) {
    // Opens a file input stream
    ifstream fIn;
    fIn.open("../" + filename);

    // Reads the header
    string header;
    if (fIn) {
        getline(fIn, header);
    }

    string owner, adjective, type, attribute, newLine;
    int modifier, value;
    char comma, quote, newline;

    // Keep looping while the stream is in a good state, and we are not at the end of the file
    while (fIn && fIn.peek() != EOF) {
        // Read the owner
        if (fIn.peek() == '"') {
            fIn >> quote;
            // Read in the quote, then read until the next quote
            // Now the delimiter is a double quote, not just a comma
            getline(fIn, owner, '"');
            // Read in the comma after the quoted string
            fIn >> comma;
        } else if (fIn.peek() == '\n') {
            // If the owner starts with a newline, remove this character
            getline(fIn, owner, ',');
            owner = owner.substr(1);
        } else {
            getline(fIn, owner, ',');
        }

        // Read the modifier
        fIn >> modifier;
        fIn >> comma;

        // Read the adjective
        getline(fIn, adjective, ',');

        // Read the type
        getline(fIn, type, ',');

        // Read the attribute
        getline(fIn, attribute, ',');

        // Read the value
        fIn >> value;

        // Create a Trinket object and add it to the vector
        trinkets.push_back(Trinket(owner, modifier, adjective, type, attribute, value));
    }
    fIn.close();
}

#endif //PROJECT_2_FILE_INPUT_H
