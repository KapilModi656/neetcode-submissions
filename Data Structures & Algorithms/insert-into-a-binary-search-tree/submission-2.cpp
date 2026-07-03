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
    TreeNode* insertion(TreeNode* root,int val){
        if(root==NULL){
            TreeNode* a=new TreeNode(val);
            root=a;
            return a;
        }
        if(root->val<val&&root->right==NULL){
            TreeNode* a = new TreeNode(val);
            root->right=a;
            return root;
        }
        if(root->val>val&&root->left==NULL){
            TreeNode* a = new TreeNode(val);
            root->left=a;
            return root;
        }
        if(root->val>val){
            TreeNode* b=insertion(root->left,val);
            if(b!=NULL) return root;
            else return NULL;

        }
        else{
            TreeNode* b=insertion(root->right,val);
            if(b!=NULL) return root;
            else return NULL;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=insertion(root,val);
        return node;
    }
};