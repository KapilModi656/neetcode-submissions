class Solution {
public:
    void dfs(map<int,vector<int>>& adj,vector<bool>& visited,int ind,vector<int>& nums,map<int,bool>& isvisit){
        int node = nums[ind];
        visited[ind]=true;
        for(int j=2;j*j<=node;j++){
            if(node%j==0&&!isvisit.count(j)){
                isvisit[j]=true;
                for(auto it:adj[j]){
                    if(!visited[it]){
                        dfs(adj,visited,it,nums,isvisit);
                    }
                }
            }
            while(node%j==0){
                node = node/j;
            }
        }
        if(node!=1&&!isvisit.count(node)){
         
            for(auto it:adj[node]){
                if(!visited[it]){
                    dfs(adj,visited,it,nums,isvisit);
                }
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        map<int,vector<int>> adj;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=2;j*j<=nums[i];j++){
                bool flag=false;
                while(num%j==0){
                    flag=true;
                    num=num/j;
                }
                if(flag){
                    adj[j].push_back(i);
                }
            }
            if(num!=1){
                adj[num].push_back(i);
            }
        }
        vector<bool> visited(n,false);
        map<int,bool> isvisit;
        dfs(adj,visited,0,nums,isvisit);
        for(auto it:visited){
            if(it==false) return false;
        }
        return true;
    }
};