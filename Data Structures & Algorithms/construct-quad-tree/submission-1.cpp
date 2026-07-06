/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid,int x,int y,int a,int b){
        bool flag = false;
        bool flag1=false;
        for(int i=x;i<=a;i++){
            for(int j=y;j<=b;j++){
                if(grid[i][j]==1) flag1=true;
                else flag=true;
            }
        }
        if(flag&&flag1){
            Node* node = new Node(1,0);
            int mid = (a+x)/2;
            int midy = (b+y)/2;
            node->topLeft = solve(grid,x,y,mid,midy);
            node->bottomLeft = solve(grid,mid+1,y,a,midy);
            node->topRight = solve(grid,x,midy+1,mid,b);
            node->bottomRight = solve(grid,mid+1,midy+1,a,b);
            return node;
        }
        else{
            int val=0;
            if(flag1) val=1;
            Node* node = new Node(val,1);
            return node;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* node = solve(grid,0,0,n-1,n-1);
        return node;
    }
};