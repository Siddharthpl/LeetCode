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
    void same(TreeNode* p, TreeNode* q,bool& ans){
        if(p->left == NULL && q->left != NULL){
            ans = false;
            return;
        }if(p->left != NULL && q->left == NULL){
            ans = false;
            return;
         }if(p->right == NULL && q->right != NULL){
            ans = false;
            return;
        }if(p->right != NULL && q->right == NULL){
            ans = false;
            return;
         }
        if(p->val != q->val){
            ans = false;
            return;
        }
        if(p->left!= NULL && q->left!=NULL)
        same(p->left,q->left,ans);
        if(p->right!= NULL && q->right!=NULL)
        same(p->right,q->right,ans);

        return;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q!= NULL) return false;
        if(q==NULL && p!= NULL) return false;
        if(p==NULL && q==NULL ) return true;
        bool ans = true;

        if(p!= NULL && q!=NULL)
        same(p,q,ans);
        
        return ans;
    }
};