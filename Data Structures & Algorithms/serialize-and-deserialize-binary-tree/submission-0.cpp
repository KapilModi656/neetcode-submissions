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
#include <string>
class Codec {
public:
    void preorder(TreeNode* root,string& s){
        if(root==NULL) {
            s+="#,";
            return;
        }
        s+=to_string(root->val)+',';
        preorder(root->left,s);
        preorder(root->right,s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        preorder(root,st);
        return st;
        
    }

    TreeNode* solve(queue<string>& q){
        string top=q.front();
        q.pop();
        if(top=="#"){
            return NULL;
        }
        TreeNode* temp=new TreeNode(stoi(top));
        temp->left=solve(q);
        temp->right=solve(q);
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s="";
        for(int i=0;i<data.size();i++){
            if(data[i]!=','){
                s+=data[i];
            }
            else{
                q.push(s);
                s="";
            }
        }
        return solve(q);
    }
};
