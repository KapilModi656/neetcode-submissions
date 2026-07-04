class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,bool> mp;
        for(auto it:deadends){
            mp[it]=true;
        }
        queue<string> q;
        q.push("0000");
        if(mp["0000"]) return -1;
        mp["0000"]=true;
        if(target=="0000") return 0;
        int move=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto top = q.front();
                q.pop();
                if(top==target) return move;
                for(int k=0;k<4;k++){
                    char ch = top[k];
                    char a = (ch=='9')?'0':ch+1;
                    char b = (ch=='0')?'9':ch-1;
                    top[k]=a;
                    if(!mp.count(top)){
                        q.push(top);
                        mp[top]=true;
                    }
                    top[k]=b;
                    if(!mp.count(top)){
                        q.push(top);
                        mp[top]=true;
                    }
                    top[k]=ch;
                }
            }
            move++;
        }
        return -1;
    }
};