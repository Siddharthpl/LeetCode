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

    void sorting(TreeNode* root,vector<int>& Inorder){
        if(root == NULL ){
            return;
        } 
        
        sorting(root->left,Inorder);
        Inorder.push_back(root->val);
        sorting(root->right,Inorder);
        
    }

    bool Twosum(vector<int>& Inorder,int k){
        int n=Inorder.size()-1;
        int i=0;
        int j=n;
        while(i<j){
            if(Inorder[i]+Inorder[j]==k){
                return true;
            }
            if(Inorder[i]+Inorder[j]>k){
                j--;
            }
            if(Inorder[i]+Inorder[j]<k){
                i++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> Inorder;

        sorting(root,Inorder);
        bool ans;
        ans = Twosum(Inorder,k);
        return ans;
    }
};