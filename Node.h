#ifndef NODE_H
#define NODE_H

template <class Key, class Value>
class Node
{
    public:
        Key key;
        Value val;
        Node* parent;
        Node* left;
        Node* right;
        int height;
        int sub_tree_size;
        
        Node (Key key, Value val):  key(key), val(val),
                                    parent(nullptr), left(nullptr), right(nullptr),
                                    height(0), sub_tree_size(1) {}   
        ~Node() = default;
};

#endif //NODE_H