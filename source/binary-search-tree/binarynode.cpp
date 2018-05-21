// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// DO NOT compile this file
// This file is included in the binarynode.h file via #include statement
// Allows us to keep the templated class header and implementation separate

// BinaryNode to help with BinarySearchTree class
// Uses template so that ItemType can be any type
// getLeftChildPtr and setLeftChildPtr used to get/set child nodes
// getItem/setItem used to set the data stored in this node
// BinarySearchTree requires <, > relationships to be defined for ItemType
// << for  BinaryNode is defined to print the ItemType as [BN: item ]
// binarynode.cpp file is included at the bottom of the .h file
// binarynode.cpp is part of the template, cannot be compiled separately


// default constructor, children set to nullptr as default
// item contained is undefined
#include "binarynode.h"
#include "../customer.h"
template<class ItemType>
BinaryNode<ItemType>::BinaryNode() {
    //ctor
}

// destructor
template<class ItemType>
BinaryNode<ItemType>::~BinaryNode() {
    // If suffering from memory leaks, uncomment next line
    // std::cout << "Deleting " << *this << std::endl;
}

// constructor setting item
// left and right childPtr set to nullptr as default
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& item) : item {item} {
}

// true if no children, both leftPtr and rightPtr are nullptrs
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
    return leftPtr == nullptr && rightPtr == nullptr;
}

// getter for left child
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return leftPtr;
}

// setter for left child
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode* childPtr) {
    leftPtr = childPtr;
}

// getter for right child
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return rightPtr;
}

// setter for left child
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode* childPtr) {
    rightPtr = childPtr;
}

// getter for item stored at node
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return item;
}

// setter for item stored at node
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& item) {
    this->item = item;
}

template class BinaryNode<Customer>;