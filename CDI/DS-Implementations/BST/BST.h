class BST {

private:
	struct node {
			int key;
			node* left;
			node* right;
	};

	node* root;
	node* createLeaf(int key);    
	void addLeafPrvt(int key, node* ptr);
	node* findAndreturnNode(int key);
	void printInOrderPrvt(node* ptr);
	node* findAndreturnNodePrvt(int key, node* ptr);
	int findSmallestPrvt(node* ptr);
	void removeNodePrvt(int key, node* parent);
	void rmovRootMatch();
	void rmovMatch(node* parent, node* match, bool left);
	void removeSubtree(node* ptr);
		
public:
	BST();
	~BST();
	void addLeaf(int key);
	void printInOrder();
	int returnRootKey();
	void printChildren(int key);
	int findSmallest();
	void removeNode(int key);
};
