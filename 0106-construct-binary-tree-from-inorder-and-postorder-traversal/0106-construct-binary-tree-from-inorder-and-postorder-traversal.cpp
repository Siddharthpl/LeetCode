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
    void createMapping(unordered_map<int,int>& valMap,vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            valMap[inorder[i]] = i;
        }
        return;
    }

    // int search(int element, vector<int>& inorder){
    //     for(int i=0;i<inorder.size();i++){
    //         if(element == inorder[i]){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    TreeNode* constructTree(unordered_map<int,int>& valMap,vector<int>& postorder, vector<int>& inorder,int& postIndex,int inStart ,int inEnd,int size){
        if(postIndex<0) return NULL;
        if(inStart>inEnd) return NULL;

        int element = postorder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);

        // int InorderIndexOfRoot = search(element,inorder);
        int InorderIndexOfRoot = valMap[element];

        root->right = constructTree(valMap,postorder,inorder,postIndex,InorderIndexOfRoot+1,inEnd,size);
        root->left = constructTree(valMap,postorder,inorder,postIndex,inStart,InorderIndexOfRoot-1,size);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        int inStart =0;
        int inEnd = inorder.size()-1;
        int size = inorder.size()-1;

        unordered_map<int,int> valMap;
        createMapping(valMap,inorder);
        TreeNode* root = constructTree(valMap,postorder,inorder,postIndex,inStart,inEnd,size);  
        
        return root;
    }
};