template <typename T>
using Type = typename T::type; // stub file
// provided so that the BinarySearchTree can be compiled
// none of the functions are implemented
#include <iostream>
#include "binarysearchtree.h"
#include "../item.h"
#include "../customer.h"
#include "../transaction.h"
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
  // ctor
  // There is nothing to do in the default constructor.
  // All initializations are initiated when needed for better performance.
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
  // dtor
  clear(); // clear the tree.

  // clear the helper temporary array which holds the inorder array.
  if (inorderArray != nullptr)
  {
    delete[] inorderArray;
    inorderArray = nullptr;
  }
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem);
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(
    const BinarySearchTree<ItemType> &bst)
{
  // before copy make sure clean the non-empty tree.
  if (!isEmpty())
    clear();

  // if the other tree contains nodes, proceed. Otherwise, nothing to do.
  if (!bst.isEmpty())
    addPreOrder(bst.rootPtr);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
  return rootPtr == nullptr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
  return treeHeight;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
  return numberOfNodes;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &item)
{
  auto *newNodePtr = new BinaryNode<ItemType>(item);

  // if the tree is empty, new node is the root node
  if (isEmpty())
  {
    // create new root node.
    rootPtr = newNodePtr;
    treeHeight = 1;
  }
  else
  {                      // otherwise, add new item to root's child node.
    treeHeightCount = 2; // this
    // placeNode(rootPtr, newNodePtr);
    if (placeNode(rootPtr, newNodePtr) == nullptr)
    {
      // if placing does not happen, the new node memory is deleted. Therefore,
      // the memory is not leaked.
      delete newNodePtr;
      return false;
    }
  } // end if

  // At this point, one new node has been inserted successfully.
  // Now we need to update some of statistic variables.
  if (treeHeightCount > treeHeight)
  {
    treeHeight = treeHeightCount;
  }

  numberOfNodes += 1;
  return true; // We DID inserted one new node SUCCESSFULLY.
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
  if (rootPtr != nullptr)
  {
    deleteSubtree(rootPtr); // delete subTree from root down
    rootPtr = nullptr;
  }

  // lastly, reset statistics
  numberOfNodes = 0;
  treeHeight = 0;
  treeHeightCount = 0;
}

template <class ItemType>
BinaryNode<ItemType> *
BinarySearchTree<ItemType>::contains(const ItemType &item) const
{
  // tree has nothing, no need to look up.
  if (isEmpty())
    return nullptr;
  auto tmp = findNode(rootPtr, item);
  if (tmp != nullptr)
    return tmp;
  else
    return nullptr;
}

template <class ItemType>
BinaryNode<ItemType> *
BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *subTreePtr,
                                      BinaryNode<ItemType> *newNodePtr)
{
  /*
  NOTE: placenode only used for inserting new node if there is already root
  node exist. Root node adding is undertaken in add method for efficiency
  purpose. If subTreePtr is a nullptr, it returns nullptr.
   */

  // if subTreePtr is occupied, attach new node below it as a child node.
  if (subTreePtr != nullptr)
  {
    // if new node already exists in the tree, skip.
    if (subTreePtr->getItem() == newNodePtr->getItem())
    {
      treeHeightCount = -1; // -1 indicates inserting failed, so we dont have to
                            // update the tree height.
      return nullptr;
    }

    // determine which subtree to be inserted in
    if (newNodePtr->getItem() <= subTreePtr->getItem())
    { // left subtree
      BinaryNode<ItemType> *left = subTreePtr->getLeftChildPtr();

      if (left != nullptr)
      {                       // non-empty left node, keep going down.
        treeHeightCount += 1; // going down one more level,
                              // so the height goes up by 1.
        return placeNode(left, newNodePtr);
      }
      else
      {
        // left node is empty, can place it as left node of subtreePtr.
        subTreePtr->setLeftChildPtr(newNodePtr);
      } // end if
    }
    else
    { // right subtree
      BinaryNode<ItemType> *right = subTreePtr->getRightChildPtr();

      if (right != nullptr)
      {                       // non-empty right node, keep going down.
        treeHeightCount += 1; // going down one more level,
                              // so the height goes up by 1.
        return placeNode(right, newNodePtr);
      }
      else
      {
        // right node is empty, can place it as right node of subtreePtr.
        subTreePtr->setRightChildPtr(newNodePtr);
      } // end if
    }   // end if

    return newNodePtr; // new node placed successfully, return its address.

  } // end if

  return nullptr;
} // end placeNode

template <class ItemType>
BinaryNode<ItemType> *
BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType> *subTreePtr,
                                     const ItemType &target) const
{
  if (subTreePtr != nullptr)
  {
    if (subTreePtr->getItem() ==
        target) // check if we has found the target. return now.
      return subTreePtr;
    else
    {
      // Examine left subtree
      BinaryNode<ItemType> *left = subTreePtr->getLeftChildPtr();
      if (findNode(left, target) !=
          nullptr) // if left node is the target, return its address.
        return left;

      // Examine right subtree
      BinaryNode<ItemType> *right = subTreePtr->getRightChildPtr();
      if (findNode(right, target) !=
          nullptr) // if right node is the target, return its address.
        return right;
    }
  }
  return nullptr;
} // end findNode

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
  if (isEmpty())
    return;

  inorder(visit, this->rootPtr);

} // end inorder

// *WARNING: Never call rebalance method in more than one thread.
// It shares the static variable member to generate inorder array.
// Avoid rebalance-ing two trees concurrently.
template <class ItemType>
void BinarySearchTree<ItemType>::rebalance()
{
  if (isEmpty())
    return;

  if (inorderArray != nullptr)
    delete[] inorderArray;

  const int size = numberOfNodes;
  inorderArray = new ItemType[size];

  inorderArrayIndex = 0;
  inorderTraverse(addInOrderArray);

  clear();
  readTree(inorderArray, size);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n)
{
  if (n > 0)
  {
    readFullTree(arr, 0, n - 1);
    return true;
  }
  else
    return false;
}

template <class ItemType>
void BinarySearchTree<ItemType>::readFullTree(ItemType arr[], int first, int last)
{
  /*
  Note: To achieve this, I implement similar technique of quick sort.
  Add the middle element of the array, then the middle of the first haft and the
  second half excluding the previos middle node.
   */
  if (first > last)
  {
    return;
  }
  else
  {
    // Typically mid = (first + last) / 2
    // It yields adding an element to the right subtree. To produce an element
    // to the left, we use
    // mid = (first + last + 1)/2
    const size_t mid = (first + last + 1) / 2;
    add(arr[mid]); // add to root of pre order traverse to this tree.
    readFullTree(
        arr, first, mid - 1); // add the middle element on the left side.
    readFullTree(
        arr, mid + 1, last); // ad the middle element on the right side.
  }
}

template <class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const
{
  sideways(rootPtr, 0);
}

template <class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType> *current,
                                          int level) const
{
  if (current != NULL)
  {
    level++;
    sideways(current->getRightChildPtr(), level);

    // indent for readability, 4 spaces per depth level
    for (int i = level; i >= 0; i--)
    {
      cout << "    ";
    }

    cout << current->getItem() << endl; // display information of object
    sideways(current->getLeftChildPtr(), level);
  }
}

template <class ItemType>
bool BinarySearchTree<ItemType>::operator==(
    const BinarySearchTree<ItemType> &other) const
{
  if (getNumberOfNodes() != other.getNumberOfNodes())
    return false;

  // Let's compare node by node from root down of both trees.
  return compare(rootPtr, other.rootPtr);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::operator!=(
    const BinarySearchTree<ItemType> &other) const
{
  return !(*this == other);
}

template <class ItemType>
void BinarySearchTree<ItemType>::deleteSubtree(BinaryNode<ItemType> *subTreePtr)
{
  if (subTreePtr == nullptr)
    return;

  // Traverse down to left subtree.
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    deleteSubtree(subTreePtr->getLeftChildPtr());
  }

  // Traverse down to right subtree.
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    deleteSubtree(subTreePtr->getRightChildPtr());
  }

  // Leaf node deleted.
  delete subTreePtr;
} // end deleteSubtree

template <class ItemType>
void BinarySearchTree<ItemType>::inorder(void visit(ItemType &),
                                         BinaryNode<ItemType> *subTreePtr) const
{
  if (subTreePtr != nullptr)
  {
    inorder(visit, subTreePtr->getLeftChildPtr());
    ItemType item{subTreePtr->getItem()};
    visit(item);
    inorder(visit, subTreePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinarySearchTree<ItemType>::addInOrderArray(ItemType &item)
{
  inorderArray[inorderArrayIndex] = item;
  inorderArrayIndex += 1;
}

template <class ItemType>
size_t BinarySearchTree<ItemType>::inorderArrayIndex = 0;

template <class ItemType>
ItemType *BinarySearchTree<ItemType>::inorderArray = nullptr;

template <class ItemType>
bool BinarySearchTree<ItemType>::compare(
    const BinaryNode<ItemType> *subTreePtr1,
    const BinaryNode<ItemType> *subTreePtr2) const
{
  // there is no node on the left, and a node on the right.
  // Therefore, they dont have the same structure. Return false.
  if (subTreePtr1 == nullptr && subTreePtr2 != nullptr)
    return false;

  // there is a node on the left, and no node on the right.
  // Therefore, they dont have the same structure. Return false.
  if (subTreePtr1 != nullptr && subTreePtr2 == nullptr)
    return false;

  bool diff = false;
  if (subTreePtr1 == nullptr && subTreePtr2 == nullptr)
    return true; // if they dont have any node at the same location, they have
                 // the same structure, but we hit the dead end. Stop right
                 // here, and looking somewhere else.
  else
  {
    // By now, we are sure that both nodes are not empty, so we can safely call
    // node's methods.

    /*
    Note: We terminate comparing process right away at one different element.
    If the left subtree of both trees are different, we avoid searching the
    right sub tree.
     */
    if (!compare(subTreePtr1->getLeftChildPtr(),
                 subTreePtr2->getLeftChildPtr()))
      return false;
    if (!compare(subTreePtr1->getRightChildPtr(),
                 subTreePtr2->getRightChildPtr()))
      return false;

    // if both nodes from both trees has the same value, switch the return value
    // to true to indicate they are equal.
    if (subTreePtr1->getItem() == subTreePtr2->getItem())
    {
      diff = true;
    }
  }

  return diff;
} // end compare

template <class ItemType>
void BinarySearchTree<ItemType>::addPreOrder(BinaryNode<ItemType> *subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    add(subTreePtr->getItem());
    addPreOrder(subTreePtr->getLeftChildPtr());
    addPreOrder(subTreePtr->getRightChildPtr());
  }
  else
    return;
} // end addPreOrder

template class BinarySearchTree<Customer>;
// template class BinarySearchTree<Item>;
// template class BinarySearchTree<Transaction>;