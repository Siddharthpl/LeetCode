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
    ListNode* middle(ListNode*& head, ListNode*& SlowPrevHead) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                SlowPrevHead = slow;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverse(ListNode* curr, ListNode* prev) {
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        if(head->next == NULL){
            return true;
        }
        //Find mid
        ListNode* FirstHalfKaHead = head;
        ListNode* SlowPrevHead = NULL;
        ListNode* MidHead = middle(head, SlowPrevHead);

        // break
        SlowPrevHead->next = NULL;

        //Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = MidHead;
        ListNode* SecondHalfHead = reverse(curr, prev);

        // compare

        ListNode* temphead1 = FirstHalfKaHead;
        ListNode* temphead2 = SecondHalfHead;
        while(temphead1!=NULL){
            if(temphead1->val != temphead2->val){
                return false;
            }else{
                temphead1 = temphead1->next;
                temphead2 = temphead2->next;
            }
        }
        return true;
    }
};