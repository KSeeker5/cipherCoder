#ifndef ENCIPHER_H_INCLUDED
#define ENCIPHER_H_INCLUDED

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "OneCharacterStrings.h"

class Encipher
{
public:
    void setSource(std::string words);
    void formatText();

    std::string A1Z26(std::string mode);
    std::string Atbash(std::string mode);
    std::string KeyboardCipher(std::string mode);
    std::string Binary(std::string mode);
    std::string Caesar(std::string mode, std::string shift);
    std::string MorseCode(std::string mode);
    std::string Vigenere(std::string mode, std::string keyword);
    std::string Hexadecimal(std::string mode);
    std::string Base64(std::string mode);

private:
    std::ifstream readfile;

    std::string source;
    std::string temp;
    std::vector<std::string> letters;
    std::vector<std::string> shiftedLetters;
    std::vector<std::string> numbers;
    std::vector<std::string> text;
    std::vector<std::string> result;
};



void Encipher::setSource(std::string words)
{
    source = words;
}



void Encipher::formatText()
{
    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }
}



std::string Encipher::A1Z26(std::string mode)
{
    readfile.open("ciphers/A1Z26.txt");
    /*for (int i=0; i<52; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
        readfile >> temp;
        numbers.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    std::string nArr[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23",
    "24","25","26","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23",
    "24","25","26"};
    for (int i=0; i<52; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }

    formatText();

    // Build a vector of vectors for the words
    std::vector< std::vector<std::string> > singleChar;
    std::vector<std::string> tempVec;
    for (int i=0; i<text.size(); i++)
    {
        for (int j=0; j<text[i].length(); j++)
        {
            tempVec.push_back(text[i].substr(j,1));
        }
        singleChar.push_back(tempVec);
        tempVec.clear();
    }

    if (mode == "encode")
    {
        for (int i=0; i<singleChar.size(); i++)
        {
            tempVec = singleChar[i];
            for (int j=0; j<tempVec.size(); j++)
            {
                for (int k=0; k<letters.size(); k++)
                {
                    if (letters[k] == tempVec[j])
                    {
                        result.push_back(numbers[k]);
                    }
                }
                result.push_back("-");
            }
            result.pop_back();
            result.push_back(" ");
        }
    }
    else if (mode == "decode")
    {
        for (int i=0; i<26; i++)
        {
            letters.pop_back();
            numbers.pop_back();
        }

        std::vector<std::string> decryptionVec;
        bool firstTime = true;

        for (int i=0; i<singleChar.size(); i++)
        {
            tempVec = singleChar[i];
            for (int j=0; j<tempVec.size(); j++)
            {
                if (firstTime)
                {
                    temp = "";
                    for (int q=0; q<tempVec.size(); q++)
                    {
                        if (tempVec[q] == "-")
                        {
                            decryptionVec.push_back(temp);
                            temp = "";
                        }
                        else
                        {
                            temp += tempVec[q];
                        }
                    }
                    decryptionVec.push_back(temp);
                    firstTime = false;
                }
            }
            firstTime = true;
        }

        for (int q=0; q<decryptionVec.size(); q++)
        {
            for (int k=0; k<numbers.size(); k++)
            {
                if (numbers[k] == decryptionVec[q])
                {
                    result.push_back(letters[k]);
                }
            }
        }
    }


    // Recompile the string
    temp = "";
    for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
    }

    return temp;
}



std::string Encipher::Atbash(std::string mode)
{
    /*readfile.open("ciphers/Atbash.txt");
    for (int i=0; i<26; i++)
    {
        readfile >> temp;
        letters.push_back(temp);// Original Letters
        readfile >> temp;
        numbers.push_back(temp);// Transposed Alphabet
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    std::string nArr[] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i","h","g","f","e","d","c","b","a"};
    for (int i=0; i<26; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }



    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    bool added;
    oneCharString conversion(" ");
    if (mode == "encode")
    {
        for (int i=0; i<text.size(); i++)
        {
            temp = text[i];
            for (int j=0; j<text[i].length(); j++)
            {
                added = false;
                conversion.assignValue(temp.substr(j,1));
                if (conversion.isUpper())
                {
                    conversion.assignValue(conversion.toLower());
                }
                for (int k=0; k<letters.size(); k++)
                {
                    if (conversion.returnValue() == letters[k])
                    {
                        result.push_back(numbers[k]);
                        added = true;
                    }
                }
                if (!added)
                {
                    result.push_back(temp.substr(j,1));
                }
            }
            result.push_back(" ");
        }
    }
    else
    {
        for (int i=0; i<text.size(); i++)
        {
            temp = text[i];
            for (int j=0; j<text[i].length(); j++)
            {
                added = false;
                conversion.assignValue(temp.substr(j,1));
                if (conversion.isUpper())
                {
                    conversion.assignValue(conversion.toLower());
                }
                for (int k=0; k<letters.size(); k++)
                {
                    if (conversion.returnValue() == numbers[k])
                    {
                        result.push_back(letters[k]);
                        added = true;
                    }
                }
                if (!added)
                {
                    result.push_back(temp.substr(j,1));
                }
            }
            result.push_back(" ");
        }
    }
    result.pop_back();

    // Recompile string for output
    temp = "";
    for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
        //temp += " ";
    }
    return temp;
}



std::string Encipher::KeyboardCipher(std::string mode)
{
    /*readfile.open("ciphers/KeyboardCipher.txt");
    for (int i=0; i<26; i++)
    {
        readfile >> temp;
        letters.push_back(temp);// Original Letters
        readfile >> temp;
        numbers.push_back(temp);// Transposed Alphabet
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    std::string nArr[] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"};
    for (int i=0; i<26; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }



    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    bool added;
    oneCharString conversion(" ");
    if (mode == "encode")
    {
        for (int i=0; i<text.size(); i++)
        {
            temp = text[i];
            for (int j=0; j<text[i].length(); j++)
            {
                added = false;
                conversion.assignValue(temp.substr(j,1));
                if (conversion.isUpper())
                {
                    conversion.assignValue(conversion.toLower());
                }
                for (int k=0; k<letters.size(); k++)
                {
                    if (conversion.returnValue() == letters[k])
                    {
                        result.push_back(numbers[k]);
                        added = true;
                    }
                }
                if (!added)
                {
                    result.push_back(temp.substr(j,1));
                }
            }
            result.push_back(" ");
        }
    }
    else
    {
        for (int i=0; i<text.size(); i++)
        {
            temp = text[i];
            for (int j=0; j<text[i].length(); j++)
            {
                added = false;
                conversion.assignValue(temp.substr(j,1));
                if (conversion.isUpper())
                {
                    conversion.assignValue(conversion.toLower());
                }
                for (int k=0; k<letters.size(); k++)
                {
                    if (conversion.returnValue() == numbers[k])
                    {
                        result.push_back(letters[k]);
                        added = true;
                    }
                }
                if (!added)
                {
                    result.push_back(temp.substr(j,1));
                }
            }
            result.push_back(" ");
        }
    }
    result.pop_back();

    // Recompile string for output
    temp = "";
    for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
        //temp += " ";
    }
    return temp;
}



std::string Encipher::Binary(std::string mode)
{
    /*readfile.open("ciphers/Binary.txt");
    for (int i=0; i<97; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
        readfile >> temp;
        numbers.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9","!","@","#","$","%","^","&","*","(",")","-","_","+","=",";",":","\"","'","`","~","<",">","?","¿",",",".","/","{","}","[","]","€","¶","¢","\\"};
    std::string nArr[] = {"01000001","01000010","01000011","01000100","01000101","01000110","01000111","01001000","01001001","01001010","01001011","01001100","01001101","01001110","01001111","01010000","01010001","01010010","01010011","01010100","01010101","01010110","01010111","01011000","01011001","01011010","01100001","01100010","01100011","01100100","01100101","01100110","01100111","01101000","01101001","01101010","01101011","01101100","01101101","01101110","01101111","01110000","01110001","01110010","01110011","01110100","01110101","01110110","01110111","01111000","01111001","01111010","00110000","00110001","00110010","00110011","00110100","00110101","00110110","00110111","00111000","00111001","00100001","01000000","00100011","00100100","00100101","01011110","00100110","00101010","00101000","00101001","00101101","01011111","00101011","00111101","00111011","00111010","00100010","00100111","01100000","01111110","00111100","00111110","00111111","10111111","00101100","00101110","00101111","01111011","01111101","01011011","01011101","10101100","10110110","00100000","01011100"};
    for (int i=0; i<97; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }

    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    if (mode == "encode")
    {
        // Build a vector of all one-character strings
        std::vector<std::string> oneChar;
        for (int i=0; i<text.size(); i++)
        {
            for (int j=0; j<text[i].length(); j++)
            {
                oneChar.push_back(text[i].substr(j,1));
            }
            oneChar.push_back("¢");// Indicates a space
        }
        oneChar.pop_back();

        for (int i=0; i<oneChar.size(); i++)
        {
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == oneChar[i])
                {
                    result.push_back(numbers[j]);
                }
            }
        }
    }
    else if (mode == "decode")
    {
        for (int i=0; i<text.size(); i++)
        {
            for (int j=0; j<numbers.size(); j++)
            {
                if (numbers[j] == text[i])
                {
                    if (letters[j] == "¢")
                    {
                        result.push_back(" ");
                    }
                    else
                    {
                        result.push_back(letters[j]);
                    }
                }
            }
        }
    }

    // Output the result
    temp = "";
    for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
        if (mode == "encode")
        {
            temp += " ";
        }
    }
    return temp;
}



std::string Encipher::Caesar(std::string mode, std::string shift)
{
    std::string finished = "";

    /*readfile.open("ciphers/Caesar.txt");
    for (int i=0; i<26; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for (int i=0; i<26; i++)
    {
        letters.push_back(lArr[i]);
    }


    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    //string shift;
    int counter = 1;
    bool bruteForce = false;
    int shiftNum;
    //std::cout << "Input the number for the shift (or input \"brute.force\" to try every possible shift)" << std::endl << "> ";
    //cin >> shift;

    if (shift == "brute.force")
    {
        bruteForce = true;
        counter = 25;
        shiftNum = 1;
    }
    else
    {
        shiftNum = atoi(shift.c_str());
    }

    int shiftCount;
    for (int i=0; i<counter; i++)
    {
        // Get shifted alphabet vector
        shiftCount = shiftNum;
        shiftedLetters.clear();
        for (int j=0; j<letters.size(); j++)
        {
            shiftedLetters.push_back(letters[shiftCount]);

            shiftCount++;
            if (shiftCount >= 26)
            {
                shiftCount = 0;
            }
        }

        // Encrypt or decrypt the text
        result.clear();
        if (mode == "encode")
        {
            for (int j=0; j<text.size(); j++)
            {
                for (int k=0; k<text[j].length(); k++)
                {
                    oneCharString temporary(text[j].substr(k,1));

                    if (temporary.isUpper())
                    {
                        temp = temporary.toLower();
                    }
                    else
                    {
                        temp = temporary.returnValue();
                    }

                    for (int l=0; l<letters.size(); l++)
                    {
                        if (letters[l] == temp)
                        {
                            result.push_back(shiftedLetters[l]);
                        }
                    }
                }
                result.push_back(" ");
            }
        }
        else if (mode == "decode")
        {
            for (int j=0; j<text.size(); j++)
            {
                for (int k=0; k<text[j].length(); k++)
                {
                    oneCharString temporary(text[j].substr(k,1));

                    if (temporary.isUpper())
                    {
                        temp = temporary.toLower();
                    }
                    else
                    {
                        temp = temporary.returnValue();
                    }

                    for (int l=0; l<shiftedLetters.size(); l++)
                    {
                        if (shiftedLetters[l] == temp)
                        {
                            result.push_back(letters[l]);
                        }
                    }
                }
                result.push_back(" ");
            }
        }
        result.pop_back();

        // Compile and output the result
        temp = "";
        for (int j=0; j<result.size(); j++)
        {
            temp += result[j];
        }

        std::stringstream ss;
        std::string temporary;
        ss << "Shifted by " << shiftNum << ":" << std::endl;
        getline(ss,temporary);
        finished += temporary + "\n";
        ss << temp << std::endl << std::endl;
        getline(ss,temporary);
        finished += temporary + "\n\n";

        // Repeat, incrementing the number (if brute forcing)
        if (bruteForce)
        {
            shiftNum++;
        }
    }
    //cin.ignore();
    return finished;
}



std::string Encipher::MorseCode(std::string mode)
{
    /*readfile.open("ciphers/MorseCode.txt");
    for (int i=0; i<47; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
        readfile >> temp;
        numbers.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","\"","(",")","{","}","[","]",";",",","-","'","1","2","3","4","5","6","7","8","9","0"};
    std::string nArr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-...-","--.--","..-...","-.---",".-...","---.-","...-.","---.","--..--","-....-",".----.",".----","..---","...--","....-",".....","-....","--....","---..","----.","-----"};
    for (int i=0; i<47; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }

    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    if (mode == "encode")
    {
        // Build a vector of all one-character strings
        std::vector<std::string> oneChar;
        oneCharString conversion(" ");
        for (int i=0; i<text.size(); i++)
        {
            for (int j=0; j<text[i].length(); j++)
            {
                //oneChar.push_back(text[i].substr(j,1));
                conversion.assignValue(text[i].substr(j,1));
                if (conversion.isUpper())
                {
                    oneChar.push_back(conversion.toLower());
                }
                else
                {
                    oneChar.push_back(conversion.returnValue());
                }
            }
            oneChar.push_back("¢");
        }
        oneChar.pop_back();

        for (int i=0; i<oneChar.size(); i++)
        {
            for (int j=0; j<letters.size(); j++)
            {
                if (oneChar[i] == "¢" && j == 0)
                {
                    result.push_back("/");
                }
                if (letters[j] == oneChar[i])
                {
                    result.push_back(numbers[j]);
                }
            }
        }
    }
    else if (mode == "decode")
    {
        // Remove all slashes and use them to build words
        std::vector<std::string> tempVec = text;
        text.clear();
        for (int i=0; i<tempVec.size(); i++)
        {
            //std::cout << tempVec[i] << " -> ";
            if (tempVec[i] == "/")
            {
                text.push_back("¢");
                //std::cout << "¢" << std::endl;
            }
            else
            {
                text.push_back(tempVec[i]);
                //std::cout << "normal" << std::endl;
            }
        }

        for (int i=0; i<text.size(); i++)
        {
            //std::cout << text[i] << "&" << std::endl;
            for (int j=0; j<numbers.size(); j++)
            {
                if (text[i] == "¢" && j == 0)
                {
                    result.push_back(" ");
                    //std::cout << numbers[j] << " - " << text[i] << " - " << letters[j] << " - ¢" << std::endl;
                }
                else if (numbers[j] == text[i])
                {
                    result.push_back(letters[j]);
                    //std::cout << numbers[j] << " - " << text[i] << " - " << letters[j] << std::endl;
                }
            }
        }
    }

    // Output the result
    temp = "";
    for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
        if (mode == "encode")
        {
            temp += " ";
        }
    }
    return temp;
}



std::string Encipher::Vigenere(std::string mode, std::string keyword)
{
    std::string table[26][26] = {{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"},{"b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a"},{"c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b"},{"d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c"},{"e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d"},{"f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e"},{"g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f"},{"h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g"},{"i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h"},{"j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i"},{"k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j"},{"l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k"},{"m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l"},{"n","o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m"},{"o","p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n"},{"p","q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"},{"q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"},{"r","s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q"},{"s","t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r"},{"t","u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s"},{"u","v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t"},{"v","w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u"},{"w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v"},{"x","y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w"},{"y","z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x"},{"z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y"}};// Rows, Columns

    /*readfile.open("ciphers/Caesar.txt");
    for (int i=0; i<26; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for (int i=0; i<26; i++)
    {
        letters.push_back(lArr[i]);
    }
    /*readfile.open("ciphers/Vigenere.txt");
    for (int i=0; i<26; i++)
    {
        for (int j=0; j<26; j++)
        {
            readfile >> temp;
            table[i][j] = temp;
        }
    }
    readfile.close();*/

    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    // Process the text split into words to get the length of the words in the result
    std::vector<std::string> wordLength;
    for (int i=0; i<text.size(); i++)
    {
        std::stringstream ss;
        ss << text[i].length();
        ss >> temp;
        ss.clear();
        wordLength.push_back(temp);
        //std::cout << text[i] << " - " << temp << std::endl;
    }

    // Build a vector of all one-character strings
    std::vector<std::string> oneChar;
    oneCharString conversion(" ");
    for (int i=0; i<text.size(); i++)
    {
        for (int j=0; j<text[i].length(); j++)
        {
            conversion.assignValue(text[i].substr(j,1));
            if (conversion.isUpper())
            {
                oneChar.push_back(conversion.toLower());
            }
            else
            {
                oneChar.push_back(conversion.returnValue());
            }
        }
    }

    // Get the keyword for the cipher, and push it into a vector of the same length as the text
    std::vector<std::string> key;
    //string keyword;
    int counter = 0;
    //std::cout << "Enter the keyword for the cipher" << std::endl << "> ";
    //cin >> keyword;
    for (int i=0; i<oneChar.size(); i++)
    {
        conversion.assignValue(keyword.substr(counter,1));
        if (conversion.isUpper())
        {
            key.push_back(conversion.toLower());
        }
        else
        {
            key.push_back(conversion.returnValue());
        }
        counter++;
        if (counter == keyword.length())
        {
            counter = 0;
        }
    }

    // Begin messing with the data
    int pos1;
    int pos2;
    if (mode == "encode")
    {
        for (int i=0; i<oneChar.size(); i++)
        {
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == oneChar[i])
                {
                    pos1 = j;// Row
                }
            }
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == key[i])
                {
                    pos2 = j;// Column
                }
            }
            result.push_back(table[pos1][pos2]);
        }
    }
    else
    {
        for (int i=0; i<oneChar.size(); i++)
        {
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == key[i])
                {
                    pos1 = j;// Column
                }
            }
            for (int j=0; j<letters.size(); j++)
            {
                if (table[j][pos1] == oneChar[i])
                {
                    pos2 = j;// Row
                }
            }
            result.push_back(letters[pos2]);
        }
    }

    // Output the result
    temp = "";
    counter = 0;
    for (int i=0; i<wordLength.size(); i++)
    {
        for (int j=0; j<atoi(wordLength[i].c_str()); j++)
        {
            temp += result[counter];
            counter++;
        }
        if (i != wordLength.size()-1)
        {
            temp += " ";
        }
    }
    /*for (int i=0; i<result.size(); i++)
    {
        temp += result[i];
        temp += " ";
    }*/
    return temp;
    //cin.ignore();
}



std::string Encipher::Hexadecimal(std::string mode)
{
    /*readfile.open("ciphers/Hexadecimal.txt");
    for (int i=0; i<16; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
        readfile >> temp;
        numbers.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
    std::string nArr[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    for (int i=0; i<16; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }

    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();

        temp = "";
        for (int i=0; i<text.size(); i++)
        {
            temp += text[i];
            if (i != text.size()-1)
            {
                temp += " ";
            }
        }
        source = temp;
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    if (mode == "encode")
    {
        // Convert from text to binary
        Encipher encode;
        encode.setSource(source);
        source = encode.Binary("encode");
        // Format binary so it is in sets of 4 numbers instead of 8
        // Step 1: Separating words
        //std::cout << source << std::endl;
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        text.clear();
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                //text.push_back("00100000");
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        //text.pop_back();
        //text.push_back(temp);
        //std::cout << temp << std::endl;
        // Step 2: Splitting the words' length in half
        int tempInt = text.size();
        int counter = 0;
        for (int i=0; i<tempInt; i++)
        {
            temp = text[counter];
            text[counter] = temp.substr(0,4);
            //std::cout << "done " << temp.substr(0,4) << std::endl;
            text.insert(text.begin()+counter+1, temp.substr(4,4));
            //std::cout << "yep " << temp.substr(4,4) << std::endl;
            counter += 2;
        }
        // Convert from binary to hex
        for (int i=0; i<text.size(); i++)
        {
            for (int j=0; j<letters.size(); j++)
            {
                if (numbers[j] == text[i])
                {
                    result.push_back(letters[j]);
                    //std::cout << letters[j] << std::endl;
                }
            }
        }
    }
    else
    {
        // Convert from hex to binary, then to text
        // Format hex so it is in sets of 2 numbers
        //std::cout << source << std::endl;
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        text.clear();
        for (int i=0; i<source.length(); i+=2)
        {
            text.push_back(source.substr(i,2));
        }
        // Convert hex straight to 8 number binary
        std::string binaryNum = "";
        for (int i=0; i<text.size(); i++)
        {
            temp = text[i].substr(0,1);
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == temp)
                {
                    binaryNum += numbers[j];
                }
            }
            temp = text[i].substr(1,1);
            for (int j=0; j<letters.size(); j++)
            {
                if (letters[j] == temp)
                {
                    binaryNum += numbers[j];
                }
            }
            if (i != text.size()-1)
            {
                binaryNum += " ";
            }
        }
        // Convert from binary to text
        Encipher encode;
        encode.setSource(binaryNum);
        temp = encode.Binary("decode");
    }

    // Recompile string for output
    if (mode == "encode")
    {
        temp = "";
        for (int i=0; i<result.size(); i++)
        {
            temp += result[i];
            //temp += " ";
        }
    }
    return temp;
}



std::string Encipher::Base64(std::string mode)
{
    int zerosAdded = 0;

    /*readfile.open("ciphers/Base64.txt");
    for (int i=0; i<64; i++)
    {
        readfile >> temp;
        letters.push_back(temp);
        readfile >> temp;
        numbers.push_back(temp);
    }
    readfile.close();*/
    std::string lArr[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9","+","/"};
    std::string nArr[] = {"000000","000001","000010","000011","000100","000101","000110","000111","001000","001001","001010","001011","001100","001101","001110","001111","010000","010001","010010","010011","010100","010101","010110","010111","011000","011001","011010","011011","011100","011101","011110","011111","100000","100001","100010","100011","100100","100101","100110","100111","101000","101001","101010","101011","101100","101101","101110","101111","110000","110001","110010","110011","110100","110101","110110","110111","111000","111001","111010","111011","111100","111101","111110","111111"};
    for (int i=0; i<64; i++)
    {
        letters.push_back(lArr[i]);
        numbers.push_back(nArr[i]);
    }

    if (source.substr(0,1) == "\"")// A quote is detected
    {
        readfile.open(source.substr(1,source.length()-2).c_str());
        while (!readfile.eof() && readfile >> temp)
        {
            text.push_back(temp);
        }
        readfile.close();

        temp = "";
        for (int i=0; i<text.size(); i++)
        {
            temp += text[i];
            if (i != text.size()-1)
            {
                temp += " ";
            }
        }
        source = temp;
    }
    else
    {
        int pos1 = 0;
        int pos2 = 0;
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            if (source.substr(i,1) == " ")
            {
                text.push_back(temp);
                temp = "";
            }
            else
            {
                temp += source.substr(i,1);
            }
        }
        text.push_back(temp);
    }

    if (mode == "encode")
    {
        // Convert from text to binary (groups of 6), then to base64
        // Step 1: Converting text to binary
        Encipher convert;
        convert.setSource(source);
        std::string binaryText = convert.Binary("encode");

        // Remove spaces from binary text
        for (int i=0; i<binaryText.length(); i++)
        {
            if (binaryText.substr(i,1) == " ")// A space is detected
            {
                //std::cout << "\"" << binaryText[i] << "\"" << std::endl; // Make sure the program actually found a space
                binaryText.erase(binaryText.begin()+i);
            }
        }
        //std::cout << binaryText << std::endl; // output resulting binary text

        // Create groups of 6
        int counter = 0;
        temp = "";
        text.clear();
        for (int i=0; i<binaryText.length(); i++)
        {
            counter++;
            temp += binaryText.substr(i,1);
            if (counter == 6)
            {
                counter = 0;
                text.push_back(temp);
                temp = "";
            }
        }

        if (counter == 2)
        {
            temp += "0000";
            zerosAdded = 4;
            text.push_back(temp);
            //std::cout << "==" << std::endl;
        }
        else if (counter == 4)
        {
            temp += "00";
            zerosAdded = 2;
            text.push_back(temp);
            //std::cout << "=" << std::endl;
        }

        // Output regrouped binary values (FOR TESTING)
        /*for (int i=0; i<text.size(); i++)
        {
            std::cout << text[i] << " ";
        }
        std::cout << std::endl;*/

        // Convert 6-digit binary to text
        for (int i=0; i<text.size(); i++)
        {
            for (int j=0; j<numbers.size(); j++)
            {
                if (text[i] == numbers[j])
                {
                    result.push_back(letters[j]);
                }
            }
        }

        // Append equal signs if needed
        if (zerosAdded == 2)
        {
            result.push_back("=");
        }
        else if (zerosAdded == 4)
        {
            result.push_back("==");
        }
    }
    else
    {
        // Convert from base64 to 6-digit binary, then to plain text
        // Look for and remove equal signs
        for (int i=source.length()-1; i>=0; i--)
        {
            if (source.substr(i,1) == "=")
            {
                zerosAdded += 2;
                source.erase(source.begin()+i);
            }
        }
        //std::cout << source << " " << zerosAdded << std::endl; // Check source to see if only equal signs were removed (also check # of zeros)

        // Convert text to 6-digit binary
        temp = "";
        for (int i=0; i<source.length(); i++)
        {
            for (int j=0; j<numbers.size(); j++)
            {
                if (source.substr(i,1) == letters[j])
                {
                    temp += numbers[j];
                }
            }
        }
        //std::cout << temp << std::endl;// Check recompiled binary string

        // Remove zeros based on # of equal signs detected earlier
        int counter = temp.length()-1;
        for (int i=0; i<zerosAdded; i++)
        {
            temp.erase(temp.begin()+counter);
            counter--;
        }
        //std::cout << temp << std::endl;// Check to make sure correct number of zeros was removed

        // Create groups of 6
        counter = 0;
        std::string binaryText = temp;
        temp = "";
        std::string resultingText = "";
        for (int i=0; i<binaryText.length(); i++)
        {
            counter++;
            temp += binaryText.substr(i,1);
            if (counter == 8)
            {
                counter = 0;
                resultingText += temp;
                temp = "";
                resultingText += " ";
            }
        }
        resultingText.erase(resultingText.begin()+(resultingText.length()-1));
        //std::cout << resultingText << std::endl;// Make sure binary is in groups of 8

        Encipher convert;
        convert.setSource(resultingText);
        return convert.Binary("decode");
    }

    // Recompile string for output
    if (mode == "encode")
    {
        temp = "";
        for (int i=0; i<result.size(); i++)
        {
            temp += result[i];
            //temp += " ";
        }
        return temp;
    }
}

#endif // ENCIPHER_H_INCLUDED
