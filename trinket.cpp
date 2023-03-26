//
// Created by Sean St. Clair on 3/26/2023.
//

#include "trinket.h"

Trinket::Trinket() {
    owner = "Sean Doe";
    modifier = 10;
    adjective = "Flaming";
    type = "Longsword";
    attribute = "Coolness";
    value = -1;
}

Trinket::Trinket(string owner, int modifier, string adjective, string type, string attribute, int value) {
    this->owner = owner;
    this->modifier = modifier;
    this->adjective = adjective;
    this->type = type;
    this->attribute = attribute;
    this->value = value;
}

string Trinket::getOwner() const {
    return owner;
}

int Trinket::getModifier() const {
    return modifier;
}

string Trinket::getAdjective() const {
    return adjective;
}

string Trinket::getType() const {
    return type;
}

string Trinket::getAttribute() const {
    return attribute;
}

int Trinket::getValue() const {
    return value;
}

void Trinket::setOwner(string owner) {
    this->owner = owner;
}

void Trinket::setModifier(int modifier) {
    this->modifier = modifier;
}

void Trinket::setAdjective(string adjective) {
    this->adjective = adjective;
}

void Trinket::setType(string type) {
    this->type = type;
}

void Trinket::setAttribute(string attribute) {
    this->attribute = attribute;
}

void Trinket::setValue(int value) {
    this->value = value;
}

ostream &operator<<(ostream &outs, const Trinket &trinket) {
    outs << setw(15) << left << trinket.owner;
    outs << "+" << setw(5) << trinket.modifier;
    outs << setw(20) << trinket.adjective;
    outs << setw(15) << trinket.type;
    outs << setw(25) << trinket.attribute;
    outs << setw(8) << right << trinket.value << " gold";
    return outs;
}

bool operator==(const Trinket &t1, const Trinket &t2) {
    return (t1.getOwner() == t2.getOwner() && t1.getModifier() == t2.getModifier() &&
            t1.getAdjective() == t2.getAdjective() &&
            t1.getType() == t2.getType() && t1.getAttribute() == t2.getAttribute() &&
            t1.getValue() == t2.getValue());
}

bool operator>(const Trinket &t1, const Trinket &t2) {
    return (t1.getOwner() > t2.getOwner());
}

bool operator<(const Trinket &t1, const Trinket &t2) {
    return (t1.getOwner() < t2.getOwner());
}

bool operator>=(const Trinket &t1, const Trinket &t2) {
    return (t1.getOwner() >= t2.getOwner());
}

bool operator<=(const Trinket &t1, const Trinket &t2) {
    return (t1.getOwner() <= t2.getOwner());
}