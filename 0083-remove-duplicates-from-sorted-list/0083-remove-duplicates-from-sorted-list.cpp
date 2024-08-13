/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        if(head->next == NULL) return head;
        ListNode* temp = head;
        while(temp != NULL && temp->next!=NULL){
            ListNode* forward = temp->next;
            if(temp->val == forward->val ){
                temp->next = forward->next;
                forward->next = NULL;
            }else{
                temp = temp->next;
            }
        }
        return head;
        
    }
};