#include "Pair.h"

bool Pair::operator<(const Pair& pair_two)
{
    if(sales < pair_two.sales)
    {
        return true;
    }

    if (sales > pair_two.sales)
    {
        return false;
    }

    if(typeID < pair_two.typeID)
    {
        return true;
    }

    return false;
}

bool Pair::operator== (const Pair& pair_two)
{
    if (sales == pair_two.sales && typeID == pair_two.typeID)
    {
        return true;
    }
    return false;
}