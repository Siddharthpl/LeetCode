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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto it = head;
        while(it){
            n++;
            it = it->next;
        }
        int extraNodes = n%k;
        int PartSize = n/k;
        vector<ListNode*> ans(k,nullptr);
        it = head;

        for(int i=0;i<k && it;i++){
            ans[i] = it;
            int currPartSize = PartSize + (extraNodes-->0 ? 1:0);
            for(int j=0;j<currPartSize-1;j++){
                it = it->next;
            }
            auto nextPartHead = it->next;
            it->next = NULL;
            it = nextPartHead;
        }

        return ans;
    }
};