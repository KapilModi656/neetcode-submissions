class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,unordered_set<string>> adj;
        int n=wordList.size();
        map<string,bool> mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]=true;
        }
        mp[beginWord]=true;
        for(int i=0;i<beginWord.size();i++){
            char ch = beginWord[i];
            for(int k=0;k<26;k++){
                if(ch==('a'+k)) continue;
                string second = beginWord;
                second[i] = 'a'+k;
                if(mp[second]){
                    adj[beginWord].insert(second);
                    adj[second].insert(beginWord);
                }
            }
        }
        for(int j=0;j<n;j++){
            string word = wordList[j];
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(int k=0;k<26;k++){
                    if(ch==('a'+k)) continue;
                    string second = word;
                    second[i] = 'a'+k;
                    if(mp[second]){
                        adj[word].insert(second);
                        adj[second].insert(word);
                    }
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        if(beginWord==endWord) return 0;
        int length = q.size();
        int count=1;
        map<string,bool> visited;
        visited[beginWord]=true;
        while(length){
            count++;
            for(int i=0;i<length;i++){
                auto top = q.front();
                q.pop();
                for(auto it:adj[top]){
                    if(it==endWord){
                        return count;
                    }
                    if(!visited.count(it)){
                        q.push(it);
                        visited[it]=true;
                    }
                }
            }
            length = q.size();
        }
        return 0;
        
    }
};
