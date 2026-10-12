class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> inorder(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            inorder[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0) q.push(it);
            }
        }
        for(int i=0;i<n;i++) if(inorder[i]!=0) return {};
        return ans;
    }
};
