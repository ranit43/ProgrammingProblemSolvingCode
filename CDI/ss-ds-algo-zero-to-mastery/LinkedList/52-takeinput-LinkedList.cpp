#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

void printLinkedList(Node* &head) {
	//~ Node* cur = head;
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "NULL" << endl;	
}

Node* takeInput() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1) {
	   
		Node* n = new Node(data);
		
		if(head == NULL) {
			head = n;
			tail = n;
		} else {
			//~ inserting at tail
			tail->next = n;
			tail = n;  
		}
		cin >> data;
	}
	
	return head;
}

int main() {
	//~ statically
	//~ Node n1(1);
	//~ Node *head = &n1;
	
	//~ Node n2(2);
	//~ Node n3(3);
	
	//~ n1.next = &n2;
	//~ n2.next = &n3;
	Node* head = takeInput();
	printLinkedList(head);
	//~ printLinkedList(head);
	
	
	//~ cout << n1.data << " " << n2.data << endl;
	
	//~ Node* head = &n1;
	
	//~ cout << head->data << endl;
	
	//~ Dynamically
	//~ Node *n3 = new Node(3);
	//~ Node* n4 = new Node(4);
	//~ n3->next - n4;
	
	return 0; 
}
