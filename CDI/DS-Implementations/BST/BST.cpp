#include <iostream>
#include <cstdlib>
#include <climits>

#include "BST.h"

using namespace std;

BST::BST()
{
    root = nullptr;
}
BST::node* BST::createLeaf(int key)
{
    node* nd = new node;
    nd->key = key;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

void BST::addLeaf(int key)
{
    addLeafPrvt(key, root);
}
/*
Store every value only once. Same value not stored twice in here.
*/
void BST::addLeafPrvt(int key, node* ptr)
{
    if(root == nullptr)
    {
        root = createLeaf(key);
    }
    else if(key < ptr->key)
    {
        if(ptr->left != nullptr)
        {
            addLeafPrvt(key, ptr->left);
        }
        else
        {
            ptr->left = createLeaf(key);
        }
    }
    else if(key > ptr->key)
    {
        if(ptr->right != nullptr)
        {
            addLeafPrvt(key, ptr->right);
        }
        else
        {
            ptr->right = createLeaf(key);
        }
    }
    else
    {
        cout << "The key " << key << "has already been added to the BST.\n";
    }
    return;
}

void BST::printInOrder()
{
    printInOrderPrvt(root);
    return;
}

void BST::printInOrderPrvt(node* ptr)
{
    if(root != nullptr)
    {
        if(ptr->left != nullptr)
        {
            printInOrderPrvt(ptr->left);
        }
        cout << ptr->key << " ";
        if(ptr->right != nullptr)
        {
            printInOrderPrvt(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty.\n";
    }
    return;
}

BST::node* BST::findAndreturnNode(int key)
{
    return findAndreturnNodePrvt(key, root);
}

BST::node* BST::findAndreturnNodePrvt(int key, node* ptr)
{
    if(ptr != nullptr )
    {
        if(ptr->key == key)
        {
            return ptr;
        }
        else if( key < ptr->key )
        {
            return findAndreturnNodePrvt(key, ptr->left);
        }
        else if(key > ptr->key)
        {
            return findAndreturnNodePrvt(key, ptr->right);
        }
    }


    return nullptr;

}

int BST::returnRootKey() {
    if(root != nullptr ) {
        return root->key;
    }
    return INT_MIN;
}

void BST::printChildren(int key) {
    node* nodeOfKey = findAndreturnNode(key);
    if(nodeOfKey != nullptr) {
        cout << "Key: " << nodeOfKey->key << endl;
        cout << "Left Child: ";
        nodeOfKey->left == nullptr ? cout << "Null" : cout << nodeOfKey->left->key;
        cout << endl;

        cout << "Right Child: ";
        nodeOfKey->right == nullptr ? cout << "Null" : cout << nodeOfKey->right->key;
        cout << endl;
        return;
    }
    cout << "The key " << key << " is not found in the BST" << endl;
    return;
}

int BST::findSmallest() {
    return findSmallestPrvt(root);
}

int BST::findSmallestPrvt(node* ptr) {
    if(root == nullptr) {
        cout << "The tree is empty" << endl;
        return INT_MAX;
    }

    if(ptr->left != nullptr) {
        return findSmallestPrvt(ptr->left);
    }

    return ptr->key;
}

//BST::removeRootMatch();

void BST::removeNode(int key) {
    removeNodePrvt(key, root);
}

void BST::removeNodePrvt(int key, node* parent) {
    if(root == nullptr) {
        cout << "rmNdPrvt: The tree is empty\n";
        return;
    }
    if(root->key == key) {
        rmovRootMatch();
    }
    else {
        //what if it equals to the current node??
        // key == parent->key
        // as we are always checking the left and right at the parent node
        // so if it is equals to a node it will be checked from the parent node
        // of that equal node.

        if(key < parent->key && parent->left != nullptr) {
            parent->left->key == key ? rmovMatch(parent, parent->left, true)
            : removeNodePrvt(key, parent->left);
        }
        else if( key > parent->key && parent->right != nullptr) {
            parent->right->key == key ? rmovMatch(parent, parent->right, false)
            : removeNodePrvt(key, parent->right);
        }
        else {
            cout << "The key" << key << "was not found in the tree\n";
        }
    }
    return;

}

void BST::rmovRootMatch() {

	if( root != nullptr ) {
			node* delptr = root;
			int rootKey = root->key;
			int smallestInRightSubTree;
			
			//~ case 0 : when there is 0 (no) children of root
			
			if(root->left == nullptr && root->right == nullptr ) {
				root = nullptr;
				delete delptr;
			}
			
			//~ Case 1: 1 child (either left or right)
			else if(root->left == nullptr && root->right != nullptr) {
				root = root->right;
				delptr->right = nullptr;
				delete delptr;
				cout << "case 1(right): The root node with key " << rootKey << " was deleted. "
				<< "The new root contains key " << root->key << endl;
			}
			else if(root->left != nullptr && root->right == nullptr) {
				root  = root->left;
				delptr->right = nullptr;
				delete delptr;
				cout << "case 1 (left): The root node with key " << rootKey << " was deleted. "
				<< "The new root contains key " << root->key << endl;
			}
			else {
				//~ Case 2: 2 children of the root
				smallestInRightSubTree = findSmallestPrvt(root->right);
				removeNodePrvt(smallestInRightSubTree, root);
				root->key = smallestInRightSubTree;
				cout << "The root key containing key " << rootKey << " was overwritten with the key " << root->key << endl;
			}
	}
	cout <<  "Tree is empty so the root can not be removed." << endl;
}

void BST::rmovMatch(node* parent, node* match, bool left) {
		if(root != nullptr) {
			
			//~ case 0: 0 children
			if(match->left == nullptr && match->right == nullptr) {
				int matchKey = match->key;
				left ? parent->left = nullptr : parent->right = nullptr;
				delete match;
				cout << "The node containing key " << matchKey << "was removed\n";
			}
			else if(match->left == nullptr && match->right != nullptr) {
				left ? parent->left = match->right : parent->right = match->right;
				match->right = nullptr;
				int matchKey = match->key;
				delete match;
				cout << "The node containing key " << matchKey << "was removed\n";
			}
			else if(match->left != nullptr && match->right == nullptr) {
				left ? parent->left = match->left : parent->right = match->left;
				int matchKey = match->key;
				match->left = nullptr;
				delete match;
				cout << "The node containing key " << matchKey << "was removed\n";
			}
			else {
				int matchKey = match->key;
				int smallestInRightSubTree = findSmallestPrvt(match->right);
				removeNodePrvt(smallestInRightSubTree, match);
				match->key = smallestInRightSubTree;
				cout << "The node containing key " << matchKey << " was overwritten with the key " << match->key << endl;
			}
			return;
		}
		cout << "Can not remove match. The tree is empty" << endl;
		return;
}

BST::~BST() {
	removeSubtree(root);
}

void BST::removeSubtree(node* ptr) {
	if(ptr !=nullptr) {
		if(ptr->left != nullptr) {
			removeSubtree(ptr->left);
		}
		if(ptr->right != nullptr) {
			removeSubtree(ptr->right);
		}
		cout << "Deleting the node containing key " << ptr->key << endl;
		delete ptr;
		return;
	}
	return;
}
