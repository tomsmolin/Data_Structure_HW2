#include "CarDealershipManager.h"

StatusType CarDealershipManager::Init()
{
    try {
        agencies = new UnionFind<TreesWrap>();
    } 
    catch (std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType CarDealershipManager::AddAgency()
{
    try {
        agencies->MakeSet(counter);
    } 
    catch (std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    }
    counter++;
    
    return SUCCESS;
}

StatusType CarDealershipManager::SellCar(int agencyID, int typeID, int k)
{
    if (agencyID >= counter)
    {
        return FAILURE;
    }
    Set<TreesWrap>* set = agencies->Find(agencyID);
    
    if (!set->val)
    {
        try {
            set->val = new TreesWrap();
        } 
        catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
    }
    
    Node<int, int>* type = set->val->types_tree.find(typeID);

    if (!type)
    {
        try {
            set->val->types_tree.insert(typeID, k);
            set->val->sales_tree.insert(Pair(k, typeID), typeID);
        } 
        catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
    }
    else
    {
        int old_sales = type->val;
        set->val->sales_tree.remove(Pair(old_sales, typeID));
        try {
            set->val->sales_tree.insert(Pair(old_sales + k, typeID), typeID);
        } 
        catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
        type->val += k;   
    }
    return SUCCESS;
}

StatusType CarDealershipManager::UniteAgencies(int agencyID1, int agencyID2)
{
    if (agencyID1 >= counter || agencyID2 >= counter)
    {
        return FAILURE;
    }
    try {
        agencies->Union(agencyID1, agencyID2);
    }
    catch (std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    }

    return SUCCESS;
}

StatusType CarDealershipManager::GetIthSoldType(int agencyID, int i, int* res)
{
    if (agencyID >= counter)
    {
        return FAILURE;
    }
    Set<TreesWrap>* set = agencies->Find(agencyID);
    if (!set->val)
    {
        return FAILURE;
    }
    if (set->val->types_tree.root->sub_tree_size <= i)
    {
        return FAILURE;
    }
    
    *res = set->val->sales_tree.select(i + 1)->val;
    return SUCCESS;
}

void CarDealershipManager::CarDealershipManager::Quit()
{
    if (!agencies)
    {
        return;
    }

    delete agencies;
}

