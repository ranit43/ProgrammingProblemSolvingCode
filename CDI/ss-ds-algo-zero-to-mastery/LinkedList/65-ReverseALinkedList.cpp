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

// O(i)
Node *insertAtIthPosition(Node *head, int positionToInsert, int data)
{
  if (positionToInsert < 0)
  {
    return head;
  }
  if (positionToInsert == 0)
  {
    Node *newHead = new Node(data);
    newHead->next = head;
    return newHead;
  }
  // positions are 0 based
  int currentIndex = 0;
  Node *currentNode = head;
  // traversing till i-1 th index
  while (currentIndex < positionToInsert - 1 && currentNode)
  {
    currentNode = currentNode->next;
    currentIndex++;
  }
  if (currentNode)
  {
    Node *newNode = new Node(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
  return head;
}

Node *deleteIthNode(Node *head, int positionToDelete)
{
  if (positionToDelete < 0)
  {
    return head;
  }
  if (positionToDelete == 0 && head)
  {
    Node *newHead = head->next;
    head->next = NULL;
    delete head;
    return newHead;
  }
  int currentNodeIndex = 0;
  Node *currentNode = head;
  while (currentNodeIndex < positionToDelete - 1 && currentNode)
  {
    currentNode = currentNode->next;
    currentNodeIndex++;
  }
  if (currentNode && currentNode->next)
  {
    Node *nodeToDelete = currentNode->next;
    currentNode->next = currentNode->next->next;
    nodeToDelete->next = NULL;
    delete nodeToDelete;
  }
  return head;
}

int lengthRecursive(Node *head)
{
  if (head == NULL)
    return 0;

  return 1 + lengthRecursive(head->next);
}

bool isPresent(Node *head, int data)
{
  Node *currentNode = head;
  while (currentNode)
  {
    if (currentNode->data == data)
    {
      return true;
    }
    currentNode = currentNode->next;
  }

  return false;
}

bool findElementRecursive(Node *head, int data)
{
  if (!head)
    return false;

  if (head->data == data)
    return true;

  return findElementRecursive(head->next, data);
}

// LL Length > 1
// For even return the second middle node
Node *middleNode(Node *head)
{
  // initialized fast is important for the return??
  Node *slow = head;
  Node *fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast != NULL)
  {
    // even length
    return slow->next;
  }
  // odd length
  return slow;
}

Node *reverseALinkedList(Node *head)
{
  Node *prev = NULL;
  Node *currentNode = head;

  while (currentNode)
  {
    Node *nextNode = currentNode->next;
    currentNode->next = prev;

    prev = currentNode;
    currentNode = nextNode;
  }

  return prev;
}

int main()
{
  Node *head = takeInput();
  printLinkedList(head);

  head = reverseALinkedList(head);
  cout << "ReversedList List: ";
  printLinkedList(head);

  // cout << "input the position of the node and node->data " << endl;

  return 0;
}

/* 
1 2 3 -1
2 100
1 2 3 -1
0 100
1 2 3 -1
3 100
1 2 3 -1
4 100
*/

/*
 1 2 3 -1
 1-1
-1
 * */
