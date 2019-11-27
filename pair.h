#ifndef PAIR_H
#define PAIR_H

template <typename T>
class Pair{
private:
    T first;
    T second;

public:
    Pair(T firstIn, T secondIn)
        : first(firstIn), second(secondIn)
    {
    }

    T getFirst() const
    {
        return first;
    }

    T getSecond() const
    {
        return second;
    }
};

#endif
