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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* BST(ListNode*& head,int n){
        if(head == NULL || n<=0) return NULL;

        TreeNode* leftsubTree = BST(head,n/2);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftsubTree;
        head = head->next;

        TreeNode* rightsubTree = BST(head,n-n/2 -1);
        root->right = rightsubTree;
        return root;

    }

    int getlength(ListNode* head){
        int n=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        return n;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getlength(head);
        TreeNode* root = BST(head,n);
        return root;
    }
};