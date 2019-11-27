#ifndef SQUARE_H
#define SQUARE_H

#include <string>

using std::string;

#include <iostream>
using namespace std;

class Square{
private:
    char square[5][5];

public:
    Square(string key)
    {
        key = InputParser::parseKey(key);

        string letters = "abcdefghiklmnopqrstuvwxyz";

        {
            int i = 0;
            while(i < letters.size())
            {
                if(key.find(letters[i]) != string::npos)
                    letters.erase(i, 1);
                else
                    i++;
            }
        }

        int i = 0;
        for(int row = 0; row < 5; row++)
        {
            for(int col = 0; col < 5; col++)
            {
                int index = 5 * row + col;

                if(index < key.size())
                    square[row][col] = key[index];
                else
                {
                    square[row][col] = letters[i];
                    i++;
                }
            }
        }

//        for(int row = 0; row < 5; row++)
//        {
//            for(int col = 0; col < 5; col++)
//            {
//                cout << square[row][col] << " ";
//            }
//            cout << endl;
//        }
    }

    Pair<int> getCoordinates(char letter)
    {
        for(int row = 0; row < 5; row++)
            for(int col = 0; col < 5; col++)
                if(square[row][col] == letter)
                    return Pair<int>(row, col);

        return Pair<int>(-1, -1);
    }

    char getLetter(int row, int col)
    {
        return square[row][col];
    }
};

#endif
