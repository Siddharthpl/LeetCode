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
    int TreeHeight(TreeNode* root){
        if( root == NULL){
            return 0;
        }
        int left = TreeHeight(root->left);
        int right = TreeHeight(root->right);
        int maxHeight = max(left,right) + 1;
        return maxHeight;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh = TreeHeight(root->left);
        int rh = TreeHeight(root->right);
        int absD = abs(lh-rh);
        bool status = (absD<=1);

        bool lans = isBalanced(root->left);
        bool rans = isBalanced(root->right);

        if(status && lans && rans){
            return true;
        }
        else{
            return false;
        }

    }
};