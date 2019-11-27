#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <vector>
#include <string>

#include "input_parser.h"
#include "pair.h"
#include "square.h"

using std::vector;
using std::string;

#include <iostream>
using namespace std;

class Encryptor{
public:
    static string encrypt(string messageIn, string key)
    {
        Square square(key);
        vector<Pair<char>> message = InputParser::parseMessage(messageIn);

        string messageOut;
        for(int i = 0; i < message.size(); i++)
        {
            Pair<int> coordinatesFirst = square.getCoordinates(message[i].getFirst());
            Pair<int> coordinatesSecond = square.getCoordinates(message[i].getSecond());

            if(coordinatesFirst.getFirst() == coordinatesSecond.getFirst())
            {
                char newLetterFirst = square.getLetter(coordinatesFirst.getFirst(), (coordinatesFirst.getSecond() + 1)%5);
                char newLetterSecond = square.getLetter(coordinatesSecond.getFirst(), (coordinatesSecond.getSecond() + 1)%5);

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
            else if(coordinatesFirst.getSecond() == coordinatesSecond.getSecond())
            {
                char newLetterFirst = square.getLetter((coordinatesFirst.getFirst() + 1)%5, coordinatesFirst.getSecond());
                char newLetterSecond = square.getLetter((coordinatesSecond.getFirst() + 1)%5, coordinatesSecond.getSecond());

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
            else
            {
                char newLetterFirst = square.getLetter(coordinatesFirst.getFirst(), coordinatesSecond.getSecond());
                char newLetterSecond = square.getLetter(coordinatesSecond.getFirst(), coordinatesFirst.getSecond());

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
        }

        return messageOut;

//        string messageOut;
//        for(int i = 0; i < message.size(); i++)
//        {
//            //cout << message[i].getFirst() << "+" << message[i].getSecond() << " ";
//            //messageOut += (message[i]).getFirst() + (message[i]).getSecond() + " ";
//            messageOut.push_back(message[i].getFirst());
//            messageOut.append("+");
//            messageOut.push_back(message[i].getSecond());
//            messageOut.append(" ");
//        }
//
//        return messageOut;
    }

    static string decrypt(string messageIn, string key)
    {
        Square square(key);
        vector<Pair<char>> message = InputParser::parseMessage(messageIn);

        string messageOut;
        for(int i = 0; i < message.size(); i++)
        {
            Pair<int> coordinatesFirst = square.getCoordinates(message[i].getFirst());
            Pair<int> coordinatesSecond = square.getCoordinates(message[i].getSecond());

            if(coordinatesFirst.getFirst() == coordinatesSecond.getFirst())
            {
                int yFirst = (coordinatesFirst.getSecond() - 1)%5;
                int ySecond = (coordinatesSecond.getSecond() - 1)%5;
                char newLetterFirst = square.getLetter(coordinatesFirst.getFirst(), (yFirst < 0)?(5 + yFirst):yFirst);
                char newLetterSecond = square.getLetter(coordinatesSecond.getFirst(), (ySecond < 0)?(5 + ySecond):ySecond);

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
            else if(coordinatesFirst.getSecond() == coordinatesSecond.getSecond())
            {
                int xFirst = (coordinatesFirst.getFirst() - 1)%5;
                int xSecond = (coordinatesSecond.getFirst() - 1)%5;
                char newLetterFirst = square.getLetter((xFirst < 0)?(5 + xFirst):xFirst, coordinatesFirst.getSecond());
                char newLetterSecond = square.getLetter((xSecond < 0)?(5 + xSecond):xSecond, coordinatesSecond.getSecond());

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
            else
            {
                char newLetterFirst = square.getLetter(coordinatesFirst.getFirst(), coordinatesSecond.getSecond());
                char newLetterSecond = square.getLetter(coordinatesSecond.getFirst(), coordinatesFirst.getSecond());

                messageOut.push_back(newLetterFirst);
                messageOut.push_back(newLetterSecond);
                messageOut.append(" ");
            }
        }

        return messageOut;
//        string messageOut;
//        for(int i = 0; i < message.size(); i++)
//        {
//            //cout << message[i].getFirst() << "+" << message[i].getSecond() << " ";
//            //messageOut += (message[i]).getFirst() + (message[i]).getSecond() + " ";
//            messageOut.push_back(message[i].getFirst());
//            messageOut.append("+");
//            messageOut.push_back(message[i].getSecond());
//            messageOut.append(" ");
//        }
//
//        return messageOut;
    }
};

#endif
