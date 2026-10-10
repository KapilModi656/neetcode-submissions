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
    Node* solve(Node* node,map<Node*,Node*>& mp){
        Node* newNode = new Node(node->val);
        mp[node]=newNode;
        for(auto neigh:node->neighbors){
            if(mp.count(neigh)){
                newNode->neighbors.push_back(mp[neigh]);
            }
            else{
                newNode->neighbors.push_back(solve(neigh,mp));
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        map<Node*,Node*> mp;
        return solve(node,mp);
        
    }
};
