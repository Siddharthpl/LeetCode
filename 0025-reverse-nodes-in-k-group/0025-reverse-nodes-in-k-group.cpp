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
    int getlength(ListNode* &head){
        int length =0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;

        int length = getlength(head);

        ListNode* prev = NULL;
        ListNode* curr = head;
        int position =0;

        if(length<k) return head;

        while(position<k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        if(curr!=NULL){
            ListNode* reversekahead = reverseKGroup(curr,k);
            head->next = reversekahead;
        }
        return prev;
        
    }
};