#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void printLinkedList(Node *head)
{
	//~ Node* cur = head;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

Node *takeInput()
{
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;

	while (data != -1)
	{

		Node *n = new Node(data);

		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			//~ inserting at tail
			tail->next = n;
			tail = n;
		}
		cin >> data;
	}

	return head;
}

Node *takeInputInsertAtHead()
{
	int data;
	cin >> data;
	Node *head = NULL;
	//~ Node* tail = NULL;

	while (data != -1)
	{

		Node *n = new Node(data);

		if (head == NULL)
		{
			head = n;
			//~ tail = n;
		}
		else
		{
			//~ inserting at tail
			n->next = head;
			head = n;
		}
		cin >> data;
	}

	return head;
}

int lengthOfLinkedList(Node *head)
{
	int length = 0;
	while (head)
	{
		head = head->next;
		length++;
	}
	return length;
}

// O(i)
void printIthNode(Node *head, int i)
{
	if (i < 0)
	{
		cout << "-1" << endl;
		return;
	}
	int count = 0;
	while (count < i && head)
	{
		count++;
		head = head->next;
	}

	if (head)
	{
		cout << head->data << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return;
}

int main()
{
	//~ statically
	//~ Node n1(1);
	//~ Node *head = &n1;
	//~ Node n2(2);
	//~ n1.next = &n2;

	//~ takeInput
	//~ Node* head = takeInputInsertAtHead();
	//~ printLinkedList(head);
	Node *head = takeInput();
	printLinkedList(head);

	cout << "input the node to find " << endl;
	int ithPosition;
	cin >> ithPosition;
	printIthNode(head, ithPosition);

	return 0;
}

/*
 1 2 3 -1
 1-1
-1
 * */
