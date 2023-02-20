#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

void printTree(BST* nBST) {
    nBST->printInOrder();
    cout << endl;
    return;
}

int main() {
	int treeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	BST cBST;
	cout << " Inorder: Before adding number\n";
	cBST.printInOrder();
	cout << endl;

	for(int i=0; i<16; i++) {
			cBST.addLeaf(treeKeys[i]);
	}

	cout << " Inorder: Before adding number\n";
	cBST.printInOrder();
	cout << endl;

//    printTree(cBST)

//    for(int i=0; i<16; i++) {
//        cBST.printChildren(treeKeys[i]);
//        cout << endl;
//    }
	cout << endl;
	cBST.printChildren(cBST.returnRootKey());
	cout << endl;

	cout << "Smallest in the BST: " << cBST.findSmallest() << endl;
	cout << "Enter a key value to delete. Enter -1 to stop the process." << endl;
	int iptKey=0;
	cout << "Delete Node: ";
	while(cin >> iptKey && iptKey!=-1) {
		cout << endl;
		cBST.removeNode(iptKey);
		cBST.printInOrder();
		cout << endl << "Delete Node: ";;
		
	}

    return 0;
}
