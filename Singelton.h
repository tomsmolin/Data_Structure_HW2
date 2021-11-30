#ifndef SINGELTON_H
#define SINGELTON_H

#include "Set.h"

template <class Value>
class Singelton
{
    public:
        int index; 
        Singelton* parent;
        Set<Value>* set;

        Singelton(int index) : index(index), parent(nullptr), set(nullptr) {}
        ~Singelton() = default;

};

#endif //SINGELTON_H