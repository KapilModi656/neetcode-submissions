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
    int depth(TreeNode* root){
        if(root==NULL) return NULL;
        int maxi = 1+depth(root->left);
        maxi = max(maxi,1+depth(root->right));
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi1 = depth(root->left);
        int maxi2 = depth(root->right);
        int maxi = diameterOfBinaryTree(root->left);
        maxi = max(maxi,diameterOfBinaryTree(root->right));
        return max(maxi,maxi1+maxi2);
    }
};
