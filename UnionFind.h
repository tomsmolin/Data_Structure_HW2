#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "Singelton.h"

#define INITIAL_SIZE 16
#define NOT_INIT -1

template <class Value>
class UnionFind
{
    public:
        Singelton<Value>** ptr_array;
        int array_size;
        int current;

        UnionFind() : ptr_array(nullptr), array_size(0), current(NOT_INIT) {}
        ~UnionFind();

        // ========= Methods ==========
        Set<Value>* MakeSet(int index);
        Set<Value>* Find(int index);
        Set<Value>* Union(int index_1, int index_2);

    private:
        Singelton<Value>** manageArray();

};

template <class Value>
UnionFind<Value>::~UnionFind()
{
    if (ptr_array)
    {
        for (int i=0; i < current; i++)
        {
            if (ptr_array[i]->set)
            {
                delete ptr_array[i]->set;
                ptr_array[i]->set = nullptr;
            }
            
            ptr_array[i]->parent = nullptr;
            delete ptr_array[i];
            ptr_array[i] = nullptr;
        }
        delete [] ptr_array;
    }
}

template <class Value>
Set<Value>* UnionFind<Value>::MakeSet(int index)
{
    try {
        manageArray();
        Singelton<Value>* singelton = new Singelton<Value>(index);
        singelton->set = new Set<Value>(index);
        ptr_array[current] = singelton;
        current++;
        return singelton->set;
    } 
    catch (std::bad_alloc& e) {
        throw;
    }
}

template <class Value>
Set<Value>* UnionFind<Value>::Find(int index)
{
    Singelton<Value>* singelton = ptr_array[index];
    if (!singelton)
    {
        return nullptr;
    }

    Singelton<Value>* temp = singelton;
    while(temp->parent)
    {
        temp = temp->parent;
    }

    Singelton<Value>* head = temp;
    while(singelton->parent)
    {
        temp = singelton->parent;
        singelton->parent = head;
        singelton = temp;
    }
    return head->set;
}

template <class Value>
Set<Value>* UnionFind<Value>::Union(int index_1, int index_2)
{
    Set<Value>* set_1 = Find(index_1);
    Set<Value>* set_2 = Find(index_2);
    
    if (set_1 == set_2)
    {
        return set_1;
    }

    Singelton<Value>* head_1 = ptr_array[set_1->head_index];
    Singelton<Value>* head_2 = ptr_array[set_2->head_index];
    if (set_1->set_size > set_2->set_size)
    {
       head_2->parent = head_1;
       set_1->set_size += set_2->set_size;
       
       if (!set_1->val && set_2->val)
       {
            set_1->val = set_2->val;
            set_2->val = nullptr;
       }
       if (set_1->val && set_2->val)
       {
            Value* val_to_delete = set_1->val;
            set_1->val = *(set_1->val) + *(set_2->val); 
            delete val_to_delete;
       }

       delete set_2;
       head_2->set = nullptr;
       if (!set_1->val)
       {
           return nullptr;
       }
       return set_1;
    }
    else
    {
       head_1->parent = head_2;

       set_2->set_size += set_1->set_size;

       if (!set_1->val && set_2->val)
       {
           set_2->val = set_2->val;
       }
       if (set_1->val && !set_2->val)
       {
           set_2->val = set_1->val;
           set_1->val = nullptr;
       }
       if (set_1->val && set_2->val)
       {
           Value* val_to_delete = set_2->val;
           set_2->val = *(set_1->val) + *(set_2->val);
           delete val_to_delete;
       }

       delete set_1;
       head_1->set = nullptr;
       if (!set_2->val)
       {
           return nullptr;
       }
       return set_2;
    }
}

template <class Value>
Singelton<Value>** UnionFind<Value>::manageArray()
{
    if (!ptr_array)
    {
        try {
            ptr_array = new Singelton<Value>*[INITIAL_SIZE]();
        } 
        catch (std::bad_alloc& e) {
            throw;
        }

        array_size = INITIAL_SIZE;
        current = 0;
    }

    if (array_size <= current*2)
    {
        array_size = array_size*2;
        try {
            Singelton<Value>** new_ptr_array = new Singelton<Value>*[array_size]();

            for (int i = 0; i < current; i++)
            {
                new_ptr_array[i] = ptr_array[i];
                ptr_array[i] = nullptr;
            }
            delete [] ptr_array;
            ptr_array = new_ptr_array;
            new_ptr_array = nullptr;
        } 
        catch (std::bad_alloc& e) {
            throw;
        }
    }
    return ptr_array;
}

#endif //UNION_FIND_H