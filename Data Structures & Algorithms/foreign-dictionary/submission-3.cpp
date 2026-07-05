class Solution {
public:
    bool dfs(map<char,vector<char>>& adj,string& s,char node,map<char,int>& state){
        state[node] = 1;
        for(auto it:adj[node]){
            if(state[it]==1) return false;
            if(state[it]==0){
                if(!dfs(adj,s,it,state)) return false;
            }
        }
        s+=node;
        state[node]=2;
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        int length = 0;
        int n=words.size();
        for(int i=0;i<n;i++) length = max(length,(int)words[i].size());
        map<char,vector<char>> adj;
        map<char,char> mp;
        for(int i=1;i<n;i++){
            string w1 = words[i - 1];
            string w2 = words[i];
            int minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2) {
                return "";
            }
            for(int j=0;j<minLen;j++){
                char a = words[i][j];
                char b = words[i-1][j];
                if(a==b) continue;
                adj[b].push_back(a);
                mp[a]=b;
                break;
            }
            
        }
        string s;
        map<char,int> state;
        for (const string& word : words) {
            for (char c : word) {
                if (state.find(c) == state.end()) {
                    state[c] = 0; 
                }
            }
        }
        for (auto& pair : state) {
            if (pair.second == 0) {
                if (!dfs(adj,s,pair.first,state)) {
                    return "";
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;

    }
};
