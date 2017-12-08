#ifndef ONECHARACTERSTRINGS_H_INCLUDED
#define ONECHARACTERSTRINGS_H_INCLUDED

#include <iostream>
#include <string>

class oneCharString
{
public:
    oneCharString(std::string value);

    void assignValue(std::string value);
    void output();
    std::string returnValue();
    bool isUpper();
    bool isLower();
    std::string toLower();
    std::string toUpper();

private:
    std::string string1;
};

oneCharString::oneCharString(std::string value)
{
    string1 = value;
}

void oneCharString::output()
{
    std::cout << string1;
}

void oneCharString::assignValue(std::string value)
{
    string1 = value;
}

std::string oneCharString::returnValue()
{
    return string1;
}

bool oneCharString::isUpper()
{
    bool capital = false;
    if (string1 == "A")
    {
        capital = true;
    }
    else if (string1 == "B")
    {
        capital = true;
    }
    else if (string1 == "C")
    {
        capital = true;
    }
    else if (string1 == "D")
    {
        capital = true;
    }
    else if (string1 == "E")
    {
        capital = true;
    }
    else if (string1 == "F")
    {
        capital = true;
    }
    else if (string1 == "G")
    {
        capital = true;
    }
    else if (string1 == "H")
    {
        capital = true;
    }
    else if (string1 == "I")
    {
        capital = true;
    }
    else if (string1 == "J")
    {
        capital = true;
    }
    else if (string1 == "K")
    {
        capital = true;
    }
    else if (string1 == "L")
    {
        capital = true;
    }
    else if (string1 == "M")
    {
        capital = true;
    }
    else if (string1 == "N")
    {
        capital = true;
    }
    else if (string1 == "O")
    {
        capital = true;
    }
    else if (string1 == "P")
    {
        capital = true;
    }
    else if (string1 == "Q")
    {
        capital = true;
    }
    else if (string1 == "R")
    {
        capital = true;
    }
    else if (string1 == "S")
    {
        capital = true;
    }
    else if (string1 == "T")
    {
        capital = true;
    }
    else if (string1 == "U")
    {
        capital = true;
    }
    else if (string1 == "V")
    {
        capital = true;
    }
    else if (string1 == "W")
    {
        capital = true;
    }
    else if (string1 == "X")
    {
        capital = true;
    }
    else if (string1 == "Y")
    {
        capital = true;
    }
    else if (string1 == "Z")
    {
        capital = true;
    }
    return capital;
}


bool oneCharString::isLower()
{
    bool capital = false;
    bool lower = true;
    if (string1 == "A")
    {
        capital = true;
    }
    else if (string1 == "B")
    {
        capital = true;
    }
    else if (string1 == "C")
    {
        capital = true;
    }
    else if (string1 == "D")
    {
        capital = true;
    }
    else if (string1 == "E")
    {
        capital = true;
    }
    else if (string1 == "F")
    {
        capital = true;
    }
    else if (string1 == "G")
    {
        capital = true;
    }
    else if (string1 == "H")
    {
        capital = true;
    }
    else if (string1 == "I")
    {
        capital = true;
    }
    else if (string1 == "J")
    {
        capital = true;
    }
    else if (string1 == "K")
    {
        capital = true;
    }
    else if (string1 == "L")
    {
        capital = true;
    }
    else if (string1 == "M")
    {
        capital = true;
    }
    else if (string1 == "N")
    {
        capital = true;
    }
    else if (string1 == "O")
    {
        capital = true;
    }
    else if (string1 == "P")
    {
        capital = true;
    }
    else if (string1 == "Q")
    {
        capital = true;
    }
    else if (string1 == "R")
    {
        capital = true;
    }
    else if (string1 == "S")
    {
        capital = true;
    }
    else if (string1 == "T")
    {
        capital = true;
    }
    else if (string1 == "U")
    {
        capital = true;
    }
    else if (string1 == "V")
    {
        capital = true;
    }
    else if (string1 == "W")
    {
        capital = true;
    }
    else if (string1 == "X")
    {
        capital = true;
    }
    else if (string1 == "Y")
    {
        capital = true;
    }
    else if (string1 == "Z")
    {
        capital = true;
    }

    if (capital)
    {
        lower = false;
    }
    return lower;
}


std::string oneCharString::toLower()
{
    std::string conversion = "";
    if (string1 == "A")
    {
        conversion = "a";
    }
    else if (string1 == "B")
    {
        conversion = "b";
    }
    else if (string1 == "C")
    {
        conversion = "c";
    }
    else if (string1 == "D")
    {
        conversion = "d";
    }
    else if (string1 == "E")
    {
        conversion = "e";
    }
    else if (string1 == "F")
    {
        conversion = "f";
    }
    else if (string1 == "G")
    {
        conversion = "g";
    }
    else if (string1 == "H")
    {
        conversion = "h";
    }
    else if (string1 == "I")
    {
        conversion = "i";
    }
    else if (string1 == "J")
    {
        conversion = "j";
    }
    else if (string1 == "K")
    {
        conversion = "k";
    }
    else if (string1 == "L")
    {
        conversion = "l";
    }
    else if (string1 == "M")
    {
        conversion = "m";
    }
    else if (string1 == "N")
    {
        conversion = "n";
    }
    else if (string1 == "O")
    {
        conversion = "o";
    }
    else if (string1 == "P")
    {
        conversion = "p";
    }
    else if (string1 == "Q")
    {
        conversion = "q";
    }
    else if (string1 == "R")
    {
        conversion = "r";
    }
    else if (string1 == "S")
    {
        conversion = "s";
    }
    else if (string1 == "T")
    {
        conversion = "t";
    }
    else if (string1 == "U")
    {
        conversion = "u";
    }
    else if (string1 == "V")
    {
        conversion = "v";
    }
    else if (string1 == "W")
    {
        conversion = "w";
    }
    else if (string1 == "X")
    {
        conversion = "x";
    }
    else if (string1 == "Y")
    {
        conversion = "y";
    }
    else if (string1 == "Z")
    {
        conversion = "z";
    }
    return conversion;
}


std::string oneCharString::toUpper()
{
    std::string conversion = "";
    if (string1 == "a")
    {
        conversion = "A";
    }
    else if (string1 == "b")
    {
        conversion = "B";
    }
    else if (string1 == "c")
    {
        conversion = "C";
    }
    else if (string1 == "d")
    {
        conversion = "D";
    }
    else if (string1 == "e")
    {
        conversion = "E";
    }
    else if (string1 == "f")
    {
        conversion = "F";
    }
    else if (string1 == "g")
    {
        conversion = "G";
    }
    else if (string1 == "h")
    {
        conversion = "H";
    }
    else if (string1 == "i")
    {
        conversion = "I";
    }
    else if (string1 == "j")
    {
        conversion = "J";
    }
    else if (string1 == "k")
    {
        conversion = "K";
    }
    else if (string1 == "l")
    {
        conversion = "L";
    }
    else if (string1 == "m")
    {
        conversion = "M";
    }
    else if (string1 == "n")
    {
        conversion = "N";
    }
    else if (string1 == "o")
    {
        conversion = "O";
    }
    else if (string1 == "p")
    {
        conversion = "P";
    }
    else if (string1 == "q")
    {
        conversion = "Q";
    }
    else if (string1 == "r")
    {
        conversion = "R";
    }
    else if (string1 == "s")
    {
        conversion = "S";
    }
    else if (string1 == "t")
    {
        conversion = "T";
    }
    else if (string1 == "u")
    {
        conversion = "U";
    }
    else if (string1 == "v")
    {
        conversion = "V";
    }
    else if (string1 == "w")
    {
        conversion = "W";
    }
    else if (string1 == "x")
    {
        conversion = "X";
    }
    else if (string1 == "y")
    {
        conversion = "Y";
    }
    else if (string1 == "z")
    {
        conversion = "Z";
    }
    return conversion;
}

#endif // ONECHARACTERSTRINGS_H_INCLUDED
