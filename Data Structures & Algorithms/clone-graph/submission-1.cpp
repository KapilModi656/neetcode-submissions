/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,map<int,Node*>& mp){
        if(node==NULL) return NULL;
        Node* temp=new Node(node->val);
        mp[temp->val]=temp;
        for(auto it:node->neighbors){
            if(mp[it->val]){
                temp->neighbors.push_back(mp[it->val]);
            }
            else{
                temp->neighbors.push_back(solve(it,mp));
            }
        }
        mp[temp->val]=temp;
        return temp;
    }
    Node* cloneGraph(Node* node) {
        map<int,Node*> mp;
        return solve(node,mp);
    }
};
