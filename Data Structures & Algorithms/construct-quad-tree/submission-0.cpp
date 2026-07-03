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
    Node* solve(vector<vector<int>>& grid,int i,int j,int n,int m){
        bool flag0=false;
        bool flag1=false;
        for(int a=i;a<n;a++){
            for(int b=j;b<m;b++){
                if(grid[a][b]==1) flag1=true;
                else flag0=true;
            }
        }
        if(flag1&&flag0){
            Node* quant=new Node(1,0);
            int mid1=(i+n)/2;
            int mid2=(j+m)/2;
            quant->topLeft=solve(grid,i,j,mid1,mid2);
            quant->topRight=solve(grid,i,mid2,mid1,m);
            quant->bottomLeft=solve(grid,mid1,j,n,mid2);
            quant->bottomRight=solve(grid,mid1,mid2,n,m);
            return quant;
        }
        else{
            if(flag1){
                Node* quant=new Node(1,1);
                return quant;
            }
            else{
                Node* quant=new Node(0,1);
                return quant;
            }
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return solve(grid,0,0,n,m);
    }
};