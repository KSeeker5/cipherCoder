// Cipher Coder.cpp
// A command line program designed to encode and decode text using multiple different ciphers
// Usage: cipherCoder <-e/-d> <cipher> <additional cipher arguments> <-t "text to use"/-f "text file.txt"> <output file.txt>
//                    -e: encrypt                                    -f: Use a file (and specify file)
//                    -d: decrypt                                    -t: Use provided text
//                                    OUTPUT FILE NOT REQUIRED
// Alex Knipper

#include <string>
#include <sstream>

#include "Encipher.h"

using namespace std;

int main(int argc, char* argv[])// argc is length of argument list, argv is actual arguments
{// argv[0] is program call, argv[1] is mode
    // Variables Section Begins
    int argCounter = 1;// Variable made to keep track of the arguments parsed
    //int arrayLength = argc;
    string *arguments = new string[argc];// Array to hold manipulatable argument list

    string mode;// Enciphering mode
    string textHandling;// How program will handle text

    string temp;// Temporary variable to hold converted strings

    stringstream convert;// Stream meant to convert arguments
    Encipher encode;// Variable meant to perform the various algorithms

    string text;// Text to set as function source
    string output;// How the program will output text
    string result;// Result text
    // Variables Section Ends/Program Section Begins
    // Get argument list
    for (int i=0; i<argc; i++)
    {
        convert.clear();
        convert << argv[i];
        getline(convert, temp);
        arguments[i] = temp;
    }

    // Handle argv[1]
    if (arguments[1] == "-e")
    {
        mode = "encode";
    }
    else if (arguments[1] == "-d")
    {
        mode = "decode";
    }
    else if (arguments[1] == "help")
    {
        cout << "Usage: cipherCoder <-e/-d> <cipher> <additional cipher arguments> <-t \"text to use\"/-f \"text file.txt\"> <output file.txt>" << endl;
        cout << "                    -e: encrypt                                    -f: Use a file (and specify file)" << endl;
        cout << "                    -d: decrypt                                    -t: Use provided text" << endl;
        return 0;
    }
    argCounter++;

    // Increment argCounter based on argv[2]
    if (arguments[2] == "caesar" || arguments[2] == "rotational" || arguments[2] == "rot" || arguments[2] == "vigenere")
    {
        argCounter += 2;
    }
    else
    {
        argCounter++;
    }

    // Handle next argument (-f/-t)
    {
        if (arguments[argCounter] == "-f")
        {// The text will be a filename
            text = arguments[argCounter+1];
            text.insert(0,"\"");
            text.insert(text.length(),"\"");
            //cout << text << endl;
        }
        else if (arguments[argCounter] == "-t")
        {// Read in and convert plain text
            text = arguments[argCounter+1];
        }
    }
    argCounter += 2;

    //cout << argc << " - " << argCounter << endl;
    // Handle output file
    if (argc == argCounter)// No output file specified
    {
        output = "cout";
    }
    else
    {
        output = arguments[argCounter];
        //cout << output << endl;
    }

    // Handle encryption stuff
    encode.setSource(text);
    if (arguments[2] == "A1Z26" || arguments[2] == "a1z26")
    {
        result = encode.A1Z26(mode);
    }
    else if (arguments[2] == "atbash")
    {
        result = encode.Atbash(mode);
    }
    else if (arguments[2] == "keyboardCipher" || arguments[2] == "keyboard")
    {
        result = encode.KeyboardCipher(mode);
    }
    else if (arguments[2] == "binary")
    {
        result = encode.Binary(mode);
    }
    else if (arguments[2] == "caesar" || arguments[2] == "rotational" || arguments[2] == "rot")
    {// Has 2 arguments
        string shift = arguments[3];
        result = encode.Caesar(mode,shift);
    }
    else if (arguments[2] == "morseCode" || arguments[2] == "morse")
    {
        result = encode.MorseCode(mode);
    }
    else if (arguments[2] == "vigenere")
    {// Has 2 arguments
        string keyword = arguments[3];
        result = encode.Vigenere(mode,keyword);
    }
    else if (arguments[2] == "hexadecimal" || arguments[2] == "hex")
    {
        result = encode.Hexadecimal(mode);
    }
    else if (arguments[2] == "base64" || arguments[2] == "base")
    {
        result = encode.Base64(mode);
    }
    else
    {
        cout << "Failed. At least one parameter is incorrect and/or missing." << endl;
    }

    if (output == "cout")
    {
        cout << result << endl;
    }
    else
    {
        ofstream writefile;
        writefile.open(output.c_str());
        writefile << result;
        writefile.close();
        cout << "Done." << endl;
    }

    // Output Argument List (For testing)
    /*for (int i=0; i<argc; i++)
    {
        cout << arguments[i] << endl;
    }*/
    // Program Section Ends
    return 0;
}
