#include <vector>
#include <iostream>
using namespace std;

class MyCircularQueue
{
  vector<int> *data;
  int sz = -1;
  int hasElements;
  int front, rear;

public:
  MyCircularQueue(int k)
  {
    data = new vector<int>(k);
    front = -1;
    rear = -1;
    sz = k;
    hasElements = 0;
  }

  bool enQueue(int value)
  {
    if (isFull())
    {
      return false;
    }

    if (isEmpty())
    {
      front = 0;
      rear = 0;
    }
    else if (rear == sz - 1)
    {
      rear = 0;
    }
    else
    {
      rear++;
    }

    data->at(rear) = value;
    hasElements++;

    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
    {
      return false;
    }

    if (front == sz - 1)
    {
      front = 0;
    }
    else
    {
      front++;
    }

    hasElements--;

    if (hasElements == 0)
    {
      front = rear = -1;
    }

    return true;
  }

  int Front()
  {
    if (isEmpty())
      return -1;

    return data->at(front);
  }

  int Rear()
  {
    if (isEmpty())
      return -1;

    return data->at(rear);
  }

  bool isEmpty()
  {
    return hasElements == 0;
  }

  bool isFull()
  {
    return hasElements == sz;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/*
["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","deQueue","deQueue","isEmpty","isEmpty","Rear","Rear","deQueue"]
[[8],[3],[9],[5],[0],[],[],[],[],[],[],[]]
*/