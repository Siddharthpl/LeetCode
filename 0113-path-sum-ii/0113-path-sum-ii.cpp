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

    void solve(TreeNode* root, int targetSum,int sum,vector<int> output,vector<vector<int>>& ans){
        if(root == NULL){
            return ;
        }
        if(output.empty())
        output.push_back(root->val);
        sum = sum + root->val;
        if(root->left ==NULL && root->right == NULL){
            if(targetSum == sum){
                ans.push_back(output);
                return;
            }else{
                
                return;
            }    
        }
        if(root->left != nullptr){
        output.push_back(root->left->val);
         solve(root->left,targetSum,sum,output,ans); 
        output.pop_back();
        }
        if(root->right != nullptr){
        output.push_back(root->right->val);      
        solve(root->right,targetSum,sum,output,ans);
        output.pop_back();
        }

        return ;
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> output;
        vector<vector<int>> ans;
        solve(root,targetSum,sum,output,ans);
        return ans;
    }
};
        
