class Node {
public:
	int val;
	Node* next;
	Node() {
			 val = -1;
			next = nullptr;
	}
	Node(int v) {
			val = v;
			next = nullptr;
	}
};

class MyLinkedList {
private:
    Node* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int curIdx = 0;
        Node* cNode = head;
        while(cNode != nullptr && curIdx < index) {
            cNode = cNode->next;
            curIdx++;
        }
        if(cNode != nullptr && curIdx==index) {
            return cNode->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* nHead = new Node(val);
        nHead->next = head;
        head = nHead;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head == nullptr) {
            addAtHead(val);
        }
        Node* tailNode = head;
        while(tailNode->next != nullptr) {
            tailNode = tailNode->next;
        }
        Node* nTail = new Node(val);
        tailNode->next = nTail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        int cIdx = 0;
        Node* cNode = head;
        while(cNode->next != nullptr && cIdx < index-1) {
            cNode = cNode->next;
            cIdx++;
        }
        if(cIdx == index-1) {
            Node* nNode = new Node(val);
            nNode->next  = cNode->next;
            cNode->next = nNode;
        }
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index == 0) {
            Node* delNode =  head;
            head = delNode->next;
            delete delNode;
            return;
        }
        
        int cIdx = 0;
        Node* cNode = head;        
        
        while(cNode->next != nullptr && cIdx < index-1) {
            cNode = cNode->next;
            cIdx++;
        }
        if(cIdx == index-1 && cNode->next != nullptr) {
            Node* delNode =  cNode->next;
            cNode->next = delNode->next;
            delete delNode;
        }
        if(index == 0) {
            
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
