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

class Codec {
public:
    void serial(TreeNode* root,string& s){
        if(root==NULL){
            s+="null-";
            return;
        }
        s+=to_string(root->val);
        s+='-';
        serial(root->left,s);
        serial(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        serial(root,s);
        s.pop_back();
        return s;
    }
    TreeNode* deserial(vector<string> data,int& i){
        int n=data.size();
        if(i==n){
            return NULL;
        }
        if(data[i]=="null") {
            i++;
            return NULL;
        }
        int d = stoi(data[i]);
        TreeNode* node = new TreeNode(d);
        i++;
        node->left = deserial(data,i);
        node->right = deserial(data,i);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> a;
        string s = "";
        int n=data.size();
        for(int i=0;i<n;i++){
            if(data[i]!='-') s+=data[i];
            else{
                a.push_back(s);
                s="";
            }
        }
        if(s!="") a.push_back(s);
        int ind=0;
        return deserial(a,ind);
    }
};
