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
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int option1 =diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = TreeHeight(root->left)+TreeHeight(root->right);

        int Diameter = max(option1,max(option2,option3));
        return Diameter;
    }
};