#ifndef PAIR_H
#define PAIR_H

#define NOT_INIT -1

class Pair
{
    public:
        int sales;
        int typeID;

        Pair (int sales, int typeID) : sales(sales), typeID(typeID) {}
        Pair () : sales(NOT_INIT), typeID(NOT_INIT) {}
        ~Pair() = default;
            
        // ======= Operators =======
        bool operator< (const Pair& pair_two);
        bool operator== (const Pair& pair_two);
};

#endif //PAIR_H
