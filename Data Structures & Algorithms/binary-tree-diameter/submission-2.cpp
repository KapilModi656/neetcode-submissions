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
    int left(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int h=left(root->left,maxi);
        int h2=left(root->right,maxi);
        maxi=max(maxi,h+h2);
        return 1+max(h,h2);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int a1=0;
        int a2=0;
        left(root,a1);
      
        return a1;
    }
};
