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

    void univalued(TreeNode* root,int value,bool& ans){
        if(root->val != value){
            ans = false;
            return;
        }if(root->left == NULL && root->right == NULL) return;

        if(root->left!=NULL)
        univalued(root->left,value,ans);
        if(root->right!=NULL)
        univalued(root->right,value,ans);
    }

    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        bool ans = true;
        univalued(root,value,ans);
        return ans;
    }
};