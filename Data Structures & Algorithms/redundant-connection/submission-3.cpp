class Solution {
public:
    int find(vector<int>& parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node] = find(parent,parent[node]);
        return parent[node];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        vector<int> ans;
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            int root_U = find(parent,u),root_V = find(parent,v);
            if(root_U==root_V){
                ans={u,v};
                continue;
            }
            parent[root_V] = root_U;
        }
        return ans;
        
    }
};
