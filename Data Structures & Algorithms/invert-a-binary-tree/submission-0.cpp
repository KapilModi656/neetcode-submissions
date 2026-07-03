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
    void preorder(TreeNode*& root){
        if(root==NULL){
            return;
        }
        TreeNode* temp = new TreeNode(-1);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        preorder(root->left);
        preorder(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        preorder(root);
        return root;
    }
};
