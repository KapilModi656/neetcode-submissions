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
    TreeNode* traverse(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left){
            return traverse(root->left);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val<key){
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(right){
            TreeNode* last = traverse(right);
            last->left = left;
            return right;
        }
        return left;

    }
};