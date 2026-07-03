class Solution {
public:
    int findparent(vector<int>& parent,int node){
        if(node==parent[node]) return node;
        return findparent(parent,parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int u=findparent(parent,edges[i][0]);
            int v=findparent(parent,edges[i][1]);
            if(u==v){
                return edges[i];
            }
            if(indegree[u]>indegree[v]){
                indegree[u]++;
                parent[v]=u;
            }
            else{
                indegree[v]++;
                parent[u]=v;
            }
        }
        return {};
    }
};
