//---------------------------------------------------------------------------------------
// Taken from BTNode.h provided by Mohammad Kuhail, kuhailm@Umkc.edu
//---------------------------------------------------------------------------------------
#pragma once

#include <sstream>
#include <iostream>

/** A node for a Binary Tree. */
template<typename Item_Type>
struct BTNode
{
    // Data Fields
    Item_Type data;
    BTNode<Item_Type>* left;
    BTNode<Item_Type>* right;

    // Constructor
    BTNode(const Item_Type& the_data,
        BTNode<Item_Type>* left_val = NULL,
        BTNode<Item_Type>* right_val = NULL) :
        data(the_data), left(left_val), right(right_val) {}

    // Destructor (to avoid warning message)
    virtual ~BTNode() {}

    // to_string
    //O(1)
    virtual std::string to_string() const {
        std::ostringstream os;
        os << data;
        return os.str();
    }

    // Overloading the ostream insertion operator
    //O(1)
    friend std::ostream& operator<<(std::ostream& out,
        const BTNode<Item_Type>& node) {
        return out << node.to_string();
    }
}; // End BTNode