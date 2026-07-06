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
    void find(TreeNode* root, TreeNode* p, TreeNode* q,bool& flag,bool& flag1){
        if(root==NULL) return;
        if(root->val==p->val) flag=true;
        if(root->val==q->val) flag1=true;
        if(flag&&flag1) return;
        find(root->left,p,q,flag,flag1);
        find(root->right,p,q,flag,flag1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        bool flag=false;
        bool flag1=false;
        if(root->val==p->val||root->val==q->val) return root;
        find(root->left,p,q,flag,flag1);
        if(flag&&flag1){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(flag||flag1){
            return root;
        }
        return lowestCommonAncestor(root->right,p,q);
    }
};
