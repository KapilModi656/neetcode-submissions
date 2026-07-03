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
    Node* solve(Node* node,vector<Node*>& visited) {
        Node* clone = new Node(node->val);
        visited[node->val]=clone;
        for(auto it:node->neighbors){
            if(visited[it->val]!=NULL) {
                clone->neighbors.push_back(visited[it->val]);
                continue;
            }
            clone->neighbors.push_back(solve(it,visited));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        vector<Node*> visited(101,NULL);
        Node* clone = solve(node,visited);
        return clone;
    }
};
