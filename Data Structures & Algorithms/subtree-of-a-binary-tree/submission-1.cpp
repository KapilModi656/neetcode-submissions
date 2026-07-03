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
    bool isSame(TreeNode* root,TreeNode* subroot){
        if(root==NULL&&subroot==NULL) return true;
        if(root==NULL||subroot==NULL) return false;
        if(root->val==subroot->val){
            bool a=isSame(root->left,subroot->left);
            bool b=isSame(root->right,subroot->right);
            if(a&b) return true;
            else return false;
        }
        return false;
    }
    bool solve(TreeNode* root,TreeNode* subroot){
        if(root==NULL) return false;
        if(isSame(root,subroot)) return true;
        return solve(root->left,subroot)|solve(root->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=solve(root,subRoot);
        return ans;
    }
};
