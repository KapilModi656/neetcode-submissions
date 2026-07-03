class Solution {
public:
    void bfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& visited){
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q,q1;

        q.push({i,j});
        q1.push({i,j});
        bool flag=false;
        vector<vector<bool>> visited1(n,vector<bool>(m,0));
        visited[i][j]=true;
        visited1[i][j]=true;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            if(x==0||x==n-1||y==0||y==m-1){
                flag=true;
            }
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(board[nx][ny]=='O'&&!visited[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
        }
        if(!flag){
            while(!q1.empty()){
                auto top=q1.front();
                q1.pop();
                int x=top.first;
                int y=top.second;
                board[x][y]='X';
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<n&&nx>=0&&ny<m&&ny>=0){
                        if(board[nx][ny]=='O'&&!visited1[nx][ny]){
                            q1.push({nx,ny});
                            visited1[nx][ny]=true;
                        }
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!visited[i][j]){
                    bfs(board,i,j,visited);
                }
            }
        }
        
    }
};
