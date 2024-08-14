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

    ListNode* HasLoop(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
                if(fast==slow) return slow;
                
            }
        }
        return nullptr;
        
    }

    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return nullptr;
        if(head->next == NULL) return nullptr;
        ListNode* slow = head;
        ListNode* ffast = HasLoop(head);
        if(!ffast) return nullptr;
        while(slow != ffast){
            
            ffast = ffast->next;
            slow = slow->next;
        }
        return slow;
        
    }
};