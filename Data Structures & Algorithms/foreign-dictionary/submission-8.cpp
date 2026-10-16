class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        map<char,unordered_set<char>> adj;
        map<char,int> inorder;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                inorder[words[i][j]]=0;
            }
        }
        for(int i=1;i<n;i++){
            string word1=words[i-1],word2=words[i];
            int len = min(word1.size(),word2.size());
            bool flag=true;
            for(int j=0;j<len;j++){
                if(word1[j]==word2[j]) continue;
                else{
                    if(adj[word1[j]].find(word2[j])==adj[word1[j]].end()){
                        adj[word1[j]].insert(word2[j]);
                        inorder[word2[j]]++;
                    }
                    
                    flag=false;
                    break;
                }
            }
            if(flag&&word1.size()>word2.size()) return "";
        }
        queue<char> q;
        string ans="";
        for(auto it:inorder){
            if(it.second==0){
                q.push(it.first);
            }
        }
        while(!q.empty()){
            char node=q.front();
            q.pop();
            ans+=node;
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0) q.push(it);
            }
        }
        if (ans.size() < inorder.size()) {
            return "";
        }
        return ans;
    }
};
