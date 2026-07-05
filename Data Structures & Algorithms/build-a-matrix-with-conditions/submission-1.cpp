class Solution {
public:
    bool topo(vector<vector<int>>& adj,int node,vector<int>& ans,vector<int>& state){
       
        state[node]=1;
        for(auto it:adj[node]){
            if(state[it]==1){
                return false;
            }
            if(state[it]==0){
                bool flag = topo(adj,it,ans,state);
                if(!flag) return false;
            }
        }
        state[node]=2;
        ans.push_back(node);
        return true;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> adj_a(k+1),adj_l(k+1);
        
        for(int i=0;i<row.size();i++){
            adj_a[row[i][0]].push_back(row[i][1]);
        }
        for(int i=0;i<col.size();i++){
            adj_l[col[i][0]].push_back(col[i][1]);
        }

        vector<int> rows;
        vector<int> cols;
        vector<int> state(k+1,0);
       
        for(int i=1;i<k+1;i++){
            if(state[i]!=2){
                bool flag = topo(adj_a,i,rows,state);
                if(!flag) return {};
            }
        }
      
        fill(state.begin(),state.end(),0);
        for(int i=1;i<k+1;i++){
            if(state[i]!=2){
                bool flag = topo(adj_l,i,cols,state);
                if(!flag) return {};
            }
        }
        reverse(cols.begin(),cols.end());
        reverse(rows.begin(),rows.end());
        vector<int> a(k+1);
        for(int i=0;i<k;i++){
            a[rows[i]]=i;
        }
        vector<vector<int>> matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            matrix[a[cols[i]]][i]=cols[i];
        }
        return matrix;
    }
};