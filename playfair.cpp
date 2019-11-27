#include <iostream>
#include <string>
// for <streamsize>
#include<ios>
// for numeric_limits
#include<limits>

#include "input_parser.h"
#include "validation_result.h"
#include "encryptor.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Playfair cipher encryptor/decryptor" << endl
         << "Accepted input format: <e - encrypt | d - decrypt> message key" << endl;

    bool finished = false;
    while(!finished)
    {
        string operation;
        string message;
        string key;
        cout << "Input: ";

        cin >> operation >> message >> key;

        ValidationResult validation = InputParser::validate(operation, message, key);
        if(!validation.isFormatValid())
        {
            cout << validation.getMessage() << endl;
            finished = false;
            continue;
        }

        string result;
        if(operation == "e" || operation == "E")
            result = "Encrypted message: " + Encryptor::encrypt(message, key);
        else
            result = "Decrypted message: " + Encryptor::decrypt(message, key);

        cout << result << endl;

        // ask the user if they've finished
        cout << "Finished? [y/n]: ";
        char finishedMessage;
        cin >> finishedMessage;

        if(finishedMessage == 'y' || finishedMessage == 'Y')
            finished = true;
        else
            finished = false;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
