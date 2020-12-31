/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA == NULL || headB == NULL) {
        return NULL;
      }
      
      bool hasIntersection = false;
      ListNode* nodeA = headA;
      ListNode* nodeB = headB;
      int lenA=0, lenB=0;
      while(nodeA->next != NULL || nodeB->next != NULL) {
        if(nodeA->next != NULL) {
          nodeA = nodeA->next;
          lenA++;
        }
        if(nodeB->next != NULL) {
          nodeB = nodeB->next;
          lenB++;
        }
        if(nodeA == nodeB ) {
          hasIntersection = true;
        }
      }
      
      if(!hasIntersection && nodeA != nodeB) {
        return NULL;
      }
      
//       nodeA the longer and nodeB the shorter length
      if(lenB > lenA) {
        nodeA = headB;
        nodeB = headA;
        swap(lenA, lenB);
      } else {
        nodeA = headA;
        nodeB = headB;
      }
      
      while(lenA > lenB) {
        nodeA = nodeA->next;
        lenA--;
      }
      
      while(nodeA != nodeB) {
        nodeA = nodeA->next;
        nodeB = nodeB->next;
      }
      
      return nodeA;
      
    }
};

/**
1
[1]
[1]
0
0
0
[1,3]
[]
2
0
0
[]
[]
0
0
8
[4,1,8,4,5]
[5,6,1,8,4,5]
2
3
2
[1,9,1,2,4]
[3,2,4]
3
1
0
[2,6,4]
[1,5]
3
2
*/
