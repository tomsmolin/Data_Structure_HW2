#include "library2.h"
#include "CarDealershipManager.h"

void* Init() {
    CarDealershipManager *DS = new CarDealershipManager();
    StatusType res = ((CarDealershipManager*)DS)->Init();
    if (res == ALLOCATION_ERROR)
    {
        return nullptr;
    }
    
    return (void*)DS;
}

StatusType AddAgency(void *DS) {
    if (!DS)
    {
        return INVALID_INPUT;
    }
    return ((CarDealershipManager*)DS)->AddAgency();
}

StatusType SellCar(void *DS, int agencyID, int typeID, int k) {
    if (!DS || agencyID < 0 || k <= 0)
    {
        return INVALID_INPUT;
    }
    return ((CarDealershipManager*)DS)->SellCar(agencyID, typeID, k);
}

StatusType UniteAgencies(void *DS, int agencyID1, int agencyID2) {
    if (!DS || agencyID1 < 0 || agencyID2 < 0)
    {
        return INVALID_INPUT;
    }
    return ((CarDealershipManager*)DS)->UniteAgencies(agencyID1, agencyID2);
}

StatusType GetIthSoldType(void *DS, int agencyID, int i, int* res) {
    if (!DS || !res || agencyID < 0 || i < 0)
    {
        return INVALID_INPUT;
    }
    return ((CarDealershipManager*)DS)->GetIthSoldType(agencyID, i, res);
}

void Quit(void** DS)
{
    CarDealershipManager* to_delete = static_cast<CarDealershipManager*>(*DS);
    if (to_delete == nullptr)
    {
        return;
    }
    to_delete->Quit();
    delete to_delete;
    *DS = nullptr;
}