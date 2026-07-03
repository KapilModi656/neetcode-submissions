class Solution {
public:
    int solve(string beginWord,string endWord,vector<string>& arr,map<string,bool> visited){
        if(beginWord==endWord) return 1;
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[arr[i]]) continue;
            int m=beginWord.size();
            int count=0;

            for(int j=0;j<m;j++){
                if(arr[i][j]!=beginWord[j]) count++;
            }
            
            if(count==1){
                visited[arr[i]]=true;
                int a=solve(arr[i],endWord,arr,visited);
                if(a!=INT_MAX){
                    ans=min(ans,1+a);
                visited[arr[i]]=false;
                }

            
        }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool> visited;
        int ans=solve(beginWord,endWord,wordList,visited);
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
