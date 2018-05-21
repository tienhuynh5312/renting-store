// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// Edit 20 Jan 2018. Added <ItemType> for all cases
// since it was complaining under some compilers but not g++

// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarynode.h"

using namespace std;

template<class ItemType>
class BinarySearchTree
{
public:
  // constructor, empty tree
  BinarySearchTree<ItemType>();
  // constructor, tree with root
  explicit BinarySearchTree<ItemType>(const ItemType& rootItem);
  // copy constructor
  BinarySearchTree<ItemType>(const BinarySearchTree<ItemType>& bst);
  // destructor
  virtual ~BinarySearchTree<ItemType>();
  // true if no nodes
  bool isEmpty() const;
  // 0 if empty, 1 if only root, otherwise
  // max height of subtrees + 1
  int getHeight() const;
  // number of nodes and data in tree
  int getNumberOfNodes() const;
  // add a new item
  // return true if succesasfull
  // false if item already in tree or some other reason to fail
  bool add(const ItemType& item);

  //===================================
  // Remove an item
  bool remove(const ItemType& item);
  //===================================
  
  // true if item is in tree
  BinaryNode<ItemType>* contains(const ItemType& item) const;
  // dispaly a sideways ascii representation of tree
  void displaySideways() const;
  // inorder traversal: left-root-right
  // takes a function that takes a single parameter of ItemType
  // the function can modify the data in tree, but the
  // tree structure is not changed
  void inorderTraverse(void visit(ItemType&)) const;
  // create dynamic array, copy all the items to the array
  // and then read the array to re-create this tree
  void rebalance();
  // delete all nodes in tree and set root to nullptr
  void clear();
  // given an array of length n
  // create this tree to have all items in that array
  // with the minimum height
  bool readTree(ItemType arr[], int n);
  // trees are equal if they have the same structure
  // AND the same item values at all the nodes
  bool operator==(const BinarySearchTree<ItemType>&) const;
  // not == to each other
  bool operator!=(const BinarySearchTree<ItemType>&) const;
private:
  // root of the tree
  BinaryNode<ItemType>* rootPtr{ nullptr };
  // add a new node, helper function for add
  BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr,
                                  BinaryNode<ItemType>* newNodePtr);
  // find the node with given vale, helper function for contains
  BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr,
                                 const ItemType& target) const;
  // helper function for displaySideways to work recursively
  void sideways(BinaryNode<ItemType>* current, int level) const;

  // My own implementation

  // node counts for easy access.
  size_t numberOfNodes{ 0 };

  //
  size_t treeHeight{ 0 };
  void addPreOrder(BinaryNode<ItemType>* subTreePtr);
  // counting tree height when adding one item.
  size_t treeHeightCount{ 0 };

  void deleteSubtree(BinaryNode<ItemType>* subTreePtr);
  void inorder(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
  void readFullTree(ItemType arr[], int first, int last);
  
  // helper variable.
  static ItemType* inorderArray;
  static size_t inorderArrayIndex;
  static void addInOrderArray(ItemType& item);

  bool compare(const BinaryNode<ItemType>* subTreePtr1, const BinaryNode<ItemType>* subTreePtr2) const;
};

// #include "binarysearchtree.cpp"

#endif // BINARYSEARCHTREE_H