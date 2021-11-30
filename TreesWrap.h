#ifndef TREES_WRAP_H
#define TREES_WRAP_H

#include <iostream>
#include "AvlTree.h"
#include "Pair.h"

class TreesWrap
{
    public:
        AVLTree<Pair, int> sales_tree;
        AVLTree<int, int> types_tree;

        TreesWrap() : sales_tree(), types_tree() {}
        ~TreesWrap() 
        {
            sales_tree.deleteTree(sales_tree.root);
            types_tree.deleteTree(types_tree.root);
            
            sales_tree.root = nullptr;
            types_tree.root = nullptr;
        }
        
        // ======= Operators =======
        TreesWrap* operator+ (const TreesWrap& wrap_two);
};

#endif //TREES_WRAP_H