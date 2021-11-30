#include "TreesWrap.h"

TreesWrap* TreesWrap::operator+(const TreesWrap& wrap_two)
{
    try {
        TreesWrap* merge_tree_wrap = new TreesWrap();
        merge_tree_wrap->sales_tree.root = sales_tree.mergeTrees(sales_tree.root, wrap_two.sales_tree.root);
        merge_tree_wrap->types_tree.root = types_tree.mergeTrees(types_tree.root, wrap_two.types_tree.root);

        return merge_tree_wrap;
    } 
    catch (std::bad_alloc& e) {
        throw;
    } 
}

