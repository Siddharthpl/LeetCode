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
    
    bool solve(TreeNode* root, int targetSum,int sum){
        if(root == NULL){
            return false;
        }
        
        sum = sum + root->val;
        if(root->left ==NULL && root->right == NULL){
            if(targetSum == sum){
                return true;
            }else{
                false;
            }    
        }
        
        bool lans = solve(root->left,targetSum,sum);       
        bool rans = solve(root->right,targetSum,sum);

        return rans || lans;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root,targetSum,sum);
    }
};