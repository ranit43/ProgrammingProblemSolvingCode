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
    bool hasCycle(ListNode *head) {
        ListNode* fast;
        ListNode* slow;
        fast = slow = head;
        
        while(fast != NULL  && slow != NULL) {
            
            if(fast->next != NULL) {
                fast = fast->next->next;
            }
            else fast = fast->next;
            
            slow = slow->next;
            
            if(fast!= NULL && fast == slow) return true;
        }
        
        return false;
        
    }
};
