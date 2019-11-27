#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <cctype>

#include "validation_result.h"
#include "pair.h"

using std::vector;
using std::string;

class InputParser{
public:
    static ValidationResult validate(string operation, string message, string key)
    {
        if(operation != "e" && operation != "d" && operation != "E" && operation != "D")
            return ValidationResult(false, "Operation not recognised");

        // check if the input contains invalid characters
        string validCharacters = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < message.size(); i++)
        {
            if(validCharacters.find(message[i]) == string::npos)
                return ValidationResult(false, "The input contains invalid characters");
        }
        for(int i = 0; i < key.size(); i++)
        {
            if(validCharacters.find(key[i]) == string::npos)
                return ValidationResult(false, "The input contains invalid characters");
        }

        return ValidationResult(true);
    }

    static vector<Pair<char>> parseMessage(string messageIn)
    {
        messageIn = stringToLower(messageIn);
        messageIn = separateDuplicates(messageIn);

        // add padding if needed
        if(messageIn.size() % 2 != 0)
        {
            if(messageIn.back() != 'x')
                messageIn += "x";
            else
                messageIn += "q";
        }

        messageIn = replaceJ(messageIn);

        // parse for letter pairs
        vector<Pair<char>> message;

        for(int i = 0; i < messageIn.size() - 1; i += 2)
        {
            message.push_back(Pair<char>(messageIn[i], messageIn[i + 1]));
//            cout << pairS.getFirst() << "-" << pairS.getSecond() << " ";
        }

        return message;
    }

    static string parseKey(string key)
    {
        key = stringToLower(key);
        key = removeDuplicates(key);
        key = replaceJ(key);

            //cout << key << endl;
        return key;
    }

private:
    static string stringToLower(string text)
    {
        for(int i = 0; i < text.size(); i++)
            text[i] = tolower(text[i]);

        return text;
    }

    static string removeDuplicates(string text)
    {
            //cout << "Remove duplicates" << endl;
        int i = 0;
        while(i < text.size())
        {
            if(text.substr(0, i).find(text[i]) != string::npos)
                text.erase(i, 1);
            else
                i++;
        }
            //cout << "Removing complete" << endl;

        return text;
    }

    static string separateDuplicates(string text)
    {
//            cout << "Separating string" << endl;
        int i = 0;
        while(i < text.size() - 1)
        {
//                cout << "Comparing: " << text[i] << " " << text[i+1] << endl;
            if(text[i] == text[i + 1])
            {
                if(text[i] != 'x')
                {
                    text.insert(i + 1, "x");
                    i++;
                }
                else
                    text.erase(i, 1);
            }
            else
                i++;
        }

        return text;
    }

    static string replaceJ(string text)
    {
            //cout << "Replace js" << endl;
        for(int i = 0; i < text.size(); i++)
            if(text[i] == 'j')
                text[i] = 'i';

            //cout << "Replacing complete" << endl;
        return text;
    }
};

#endif
