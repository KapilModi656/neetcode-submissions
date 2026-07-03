class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string s="0000";
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        if(target=="0000") return 0;
        queue<string> q;
        q.push(s);
        dead.insert(s);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string top=q.front();
                q.pop();
                if(top==target) return moves;
                for(int k=0;k<4;k++){
                    char ch=top[k];
                    char a=(ch=='9')?'0':ch+1;
                    top[k]=a;
                    if(dead.find(top)==dead.end()){
                        dead.insert(top);
                        q.push(top);
                    }
                    char b=(ch=='0')? '9':ch-1;
                    top[k]=b;
                    if(dead.find(top)==dead.end()){
                        dead.insert(top);
                        q.push(top);
                    }
                    top[k]=ch;
                }
             
            }
            moves++;
            
        }
        return -1;
    }
};