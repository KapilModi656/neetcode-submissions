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
    int solve(TreeNode* root,int k,int& a){
        if(root==NULL) return -1;
        if(root->left){
            int b = solve(root->left,k,a);
            if(b!=-1) return b;
        }
        a++;
        if(a==k){
            return root->val;
        }
        if(root->right){
            int c = solve(root->right,k,a);
            if(c!=-1) return c;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int a=0;
        int ans = solve(root,k,a);
        return ans;
    }
};
