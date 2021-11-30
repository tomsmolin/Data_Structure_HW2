#ifndef CAR_DS_MANAGER_H
#define CAR_DS_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "UnionFind.h"
#include "library2.h"
#include "TreesWrap.h"

class CarDealershipManager
{
    public:
        UnionFind<TreesWrap>* agencies;
        int counter;

        CarDealershipManager() : agencies(nullptr), counter(0) {}
        ~CarDealershipManager() = default;
        
        // ========= Methods ==========
        StatusType Init();
        StatusType AddAgency();
        StatusType SellCar(int agencyID, int typeID, int k);
        StatusType UniteAgencies(int agencyID1, int agencyID2);
        StatusType GetIthSoldType(int agencyID, int i, int* res);
        void Quit();

};

#endif //CAR_DS_MANAGER_H