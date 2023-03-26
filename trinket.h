//
// Created by Sean St. Clair on 3/26/2023.
//

#ifndef PROJECT4_TRINKET_H
#define PROJECT4_TRINKET_H

#include <string>
#include <iomanip>

using std::string;
using std::left;
using std::ostream;
using std::right;
using std::setw;

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
    Trinket();

    // This constructor takes values for the Trinket's owner, modifier, adjective, type, attribute, and gold value
    Trinket(string owner, int modifier, string adjective, string type, string attribute, int value);

    // Getters

    string getOwner() const;

    int getModifier() const;

    string getAdjective() const;

    string getType() const;

    string getAttribute() const;

    int getValue() const;

    // Setters

    void setOwner(string owner);

    void setModifier(int modifier);

    void setAdjective(string adjective);

    void setType(string type);

    void setAttribute(string attribute);

    void setValue(int value);

    // Overloaded Operators

    // Allows a Trinket object to be printed in a well-spaced format
    friend ostream &operator<<(ostream &outs, const Trinket &trinket);

    // Allows a Trinket object to be compared with another Trinket object
    friend bool operator==(const Trinket &t1, const Trinket &t2);

    friend bool operator>(const Trinket &t1, const Trinket &t2);

    friend bool operator<(const Trinket &t1, const Trinket &t2);

    friend bool operator>=(const Trinket &t1, const Trinket &t2);

    friend bool operator<=(const Trinket &t1, const Trinket &t2);

};

#endif //PROJECT4_TRINKET_H
