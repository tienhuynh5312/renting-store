// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// Edit 20 Jan 2018. Added <ItemType> for all cases
// since it was complaining under some compilers but not g++

// BinaryNode to help with BinarySearchTree class
// Uses template so that ItemType can be any type
// getLeftChildPtr and setLeftChildPtr used to get/set child nodes
// getItem/setItem used to set the data stored in this node
// BinarySearchTree requires <, > relationships to be defined for ItemType
// << for  BinaryNode is defined to print the ItemType as [BN: item ]
// binarynode.cpp file is included at the bottom of the .h file
// binarynode.cpp is part of the template, cannot be compiled separately

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>

template<class ItemType>
class BinaryNode {
    // operator<<
    // Has to be defined in .h and not in cpp since it is not in
    // BinaryNode<ItemType>:: class
    friend std::ostream& operator<<(std::ostream& out, const BinaryNode<ItemType>& bn) {
        out << "[BN: " << bn.item << "]";
        return out;
    }
public:
    // default constructor
    BinaryNode<ItemType>();
    // constructor setting the data to be stored
    explicit BinaryNode<ItemType>(const ItemType& item);
    // destructor to cleanup
    virtual ~BinaryNode<ItemType>();
    // true if no children, both left and right child ptrs are nullptr
    bool isLeaf() const;
    // get left child, possibly nullptr
    BinaryNode<ItemType>* getLeftChildPtr() const;
    // set the left child ptr
    void setLeftChildPtr(BinaryNode<ItemType>* childPtr);
    // get right child, possibly nullptr
    BinaryNode<ItemType>* getRightChildPtr() const;
    // set the right child ptr
    void setRightChildPtr(BinaryNode<ItemType>* childPtr);
    // return the item stored
    ItemType getItem() const;
    // set the item stored to a new value
    void setItem(const ItemType& item);
private:
    // the data that will be stored
    ItemType item;
    // left child
    BinaryNode<ItemType>* leftPtr {nullptr};
    // right child
    BinaryNode<ItemType>* rightPtr {nullptr};
};

#include "binarynode.cpp"

#endif // BINARYNODE_H