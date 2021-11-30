#ifndef SET_H
#define SET_H

template <class Value>
class Set
{
    public:
        Value* val;
        int set_size;
        int head_index;

        Set(int head_index) : val(nullptr), set_size(1), head_index(head_index) {}
        ~Set() 
        {
            delete val;
            val = nullptr;
        }

};

#endif //SET_H