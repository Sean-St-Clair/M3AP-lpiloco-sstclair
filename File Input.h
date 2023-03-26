//
// Created by Sean St. Clair on 9/28/2022.
//

#ifndef PROJECT_2_FILE_INPUT_H
#define PROJECT_2_FILE_INPUT_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::ifstream;
using std::left;
using std::ostream;
using std::right;
using std::setw;
using std::string;
using std::vector;

// This class represents a magical "trinket," which is owned by a mythical adventurer. It possesses
// fields for the owner's name, as well as various whimsical attributes for the trinket itself, such as
// its defining adjective and its gold value. Some fields like "modifier" require some extant fantasy
// knowledge; in this case, a trinket's modifier is a rating of how exceptional that trinket is.
class Trinket {
private:
    string owner;
    int modifier;
    string adjective;
    string type;
    string attribute;
    int value;

public:
    // Constructors

    // Default constructor
    Trinket() {
        owner = "Sean Doe";
        modifier = 10;
        adjective = "Flaming";
        type = "Longsword";
        attribute = "Coolness";
        value = -1;
    }

    // This constructor takes values for the Trinket's owner, modifier, adjective, type, attribute, and gold value
    Trinket(string owner, int modifier, string adjective, string type, string attribute, int value) {
        this->owner = owner;
        this->modifier = modifier;
        this->adjective = adjective;
        this->type = type;
        this->attribute = attribute;
        this->value = value;
    }

    // Getters

    string getOwner() const {
        return owner;
    }

    int getModifier() const {
        return modifier;
    }

    string getAdjective() const {
        return adjective;
    }

    string getType() const {
        return type;
    }

    string getAttribute() const {
        return attribute;
    }

    int getValue() const {
        return value;
    }

    // Setters

    void setOwner(string owner) {
        this->owner = owner;
    }

    void setModifier(int modifier) {
        this->modifier = modifier;
    }

    void setAdjective(string adjective) {
        this->adjective = adjective;
    }

    void setType(string type) {
        this->type = type;
    }

    void setAttribute(string attribute) {
        this->attribute = attribute;
    }

    void setValue(int value) {
        this->value = value;
    }

    // Overloaded Operators

    // Allows a Trinket object to be printed in a well-spaced format.
    friend ostream &operator<<(ostream &outs, const Trinket &trinket) {
        outs << setw(15) << left << trinket.owner;
        outs << "+" << setw(5) << trinket.modifier;
        outs << setw(20) << trinket.adjective;
        outs << setw(15) << trinket.type;
        outs << setw(25) << trinket.attribute;
        outs << setw(8) << right << trinket.value << " gold";
        return outs;
    }

    // Allows a Trinket object to be compared with another Trinket object
    friend bool operator==(const Trinket &t1, const Trinket &t2) {
        return (t1.getOwner() == t2.getOwner() && t1.getModifier() == t2.getModifier() &&
                t1.getAdjective() == t2.getAdjective() &&
                t1.getType() == t2.getType() && t1.getAttribute() == t2.getAttribute() &&
                t1.getValue() == t2.getValue());
    }

    // TODO: add comments and better ++ placement
    friend bool operator>(const Trinket &t1, const Trinket &t2) {
        return (t1.getOwner() > t2.getOwner());
    }

    friend bool operator<(const Trinket &t1, const Trinket &t2) {
        return (t1.getOwner() < t2.getOwner());
    }

    friend bool operator>=(const Trinket &t1, const Trinket &t2) {
        return (t1.getOwner() >= t2.getOwner());
    }

    friend bool operator<=(const Trinket &t1, const Trinket &t2) {
        return (t1.getOwner() <= t2.getOwner());
    }

};

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
