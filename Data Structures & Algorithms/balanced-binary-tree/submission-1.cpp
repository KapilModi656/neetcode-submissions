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
    int depth(TreeNode* root,bool& flag){
        if(root==NULL) return 0;
        int right = depth(root->right,flag);
        int left = depth(root->left,flag);
        if(abs(right-left)>1){
            flag=false;
        }
        return 1+max(right,left);
    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        depth(root,flag);
        return flag;
    }
};
