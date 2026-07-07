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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& i,int s,int e){
        int n=preorder.size();
        if(i==n) return NULL;
        if(s==e) return NULL;
        int ind=-1;
        for(int j=s;j<e;j++){
            if(inorder[j]==preorder[i]){
                ind =j;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        node->left = solve(preorder,inorder,i,s,ind);
        node->right = solve(preorder,inorder,i,ind+1,e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        int n=preorder.size();
        return solve(preorder,inorder,ind,0,n);
    }
};
