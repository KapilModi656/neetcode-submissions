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
    TreeNode* solve(queue<int>& q,vector<int>& inorder,int i,int j){
        if(j-i==0) return NULL;
        if(j-i-1==0){
            TreeNode* temp=new TreeNode(inorder[i]);
            q.pop();
            return temp;
        }
        int top=q.front();
        int ind=-1;
        for(int a=i;a<j;a++){
            if(inorder[a]==top){
                ind=a;
                break;
            }
        }
        TreeNode* temp=new TreeNode(top);
        q.pop();
        temp->left=solve(q,inorder,i,ind);
        temp->right=solve(q,inorder,ind+1,j);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        queue<int> q;
        for(int i=0;i<preorder.size();i++){
            q.push(preorder[i]);
        }
        int n=preorder.size();
        TreeNode* ans=solve(q,inorder,0,n);
        return ans;
    }
};
