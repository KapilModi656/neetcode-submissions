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
    TreeNode* solve(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val>key){
            root->left= solve(root->left,key);
        }
        else if(root->val<key){
            root->right= solve(root->right,key);
        }
        else{
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            TreeNode* temp=get_node(root->right);
            temp->left=root->left;
            return root->right;
        }
        return root;
    }
    TreeNode* get_node(TreeNode* root){
        while(root->left!=NULL) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};