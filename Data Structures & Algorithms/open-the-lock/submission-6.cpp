class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<vector<int>,int>> q;
        int n=deadends.size();
        vector<int> curr = {0,0,0,0};
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=0;j<4;j++){
                if(curr[j]!=deadends[i][j]-'0') {
                    flag=true;
                    break;
                }
            }
            if(!flag) return -1;
        }
        bool flag4=false;
        for(int i=0;i<4;i++){
            if(curr[i]!=target[i]-'0') flag4=true;
        }
        if(!flag4) return 0;
        q.push({curr,0});
        set<vector<int>> visited;
        visited.insert(curr);
        int ans=INT_MAX;
        while(!q.empty()){
            auto a=q.front();
            vector<int> arr = a.first;
            int dist=a.second;
            q.pop();
            for(int i=0;i<4;i++){
                vector<int> b=arr;
                if(b[i]!=9) b[i]+=1;
                else b[i]=0;
                
                bool flag3=true;
                for(int j=0;j<4;j++){
                    if(b[j]!=target[j]-'0'){
                        flag3=false;
                        break;
                    }
                }
                if(visited.find(b)==visited.end()){
                    visited.insert(b);
                    if(flag3) ans=min(ans,dist+1);
                    else {
                        bool flag2=true;
                        for(int j=0;j<n;j++){
                            bool flag=true;
                            for(int k=0;k<4;k++){
                                if(b[k]!=deadends[j][k]-'0'){
                                    flag=false;
                                    break;
                                }
                            }
                            if(flag){
                                flag2=false;
                                break;
                            }
                        }
                        if(flag2) q.push({b,dist+1});
                    }
                }
                b=arr;
                if(b[i]!=0) b[i]=b[i]-1;
                else b[i]=9;
                if(visited.find(b)==visited.end()){
                    visited.insert(b);
                    flag3=true;
                    for(int j=0;j<4;j++){
                        if(b[j]!=target[j]-'0'){
                            flag3=false;
                            break;
                        }
                    }
                    if(flag3) ans=min(ans,dist+1);
                    else {
                        bool flag2=true;
                        for(int j=0;j<n;j++){
                            bool flag=true;
                            for(int k=0;k<4;k++){
                                if(b[k]!=deadends[j][k]-'0'){
                                    flag=false;
                                    break;
                                }
                            }
                            if(flag){
                                flag2=false;
                                break;
                            }
                        }
                        if(flag2) q.push({b,dist+1});
                    }
                }

            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};