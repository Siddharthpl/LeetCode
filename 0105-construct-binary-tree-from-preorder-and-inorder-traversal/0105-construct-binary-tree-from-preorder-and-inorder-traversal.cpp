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
    int search(int element, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(element == inorder[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int& preIndex,int inStart ,int inEnd,int size){
        if(preIndex>=size) return NULL;
        if(inStart>inEnd) return NULL;

        int element = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(element);

        int InorderIndexOfRoot = search(element,inorder);

        root->left = constructTree(preorder,inorder,preIndex,inStart,InorderIndexOfRoot-1,size);
        root->right = constructTree(preorder,inorder,preIndex,InorderIndexOfRoot+1,inEnd,size);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inStart =0;
        int inEnd = inorder.size();
        int size = inorder.size();
        TreeNode* root = constructTree(preorder,inorder,preIndex,inStart,inEnd,size);  
        
        return root;
                


    }
};