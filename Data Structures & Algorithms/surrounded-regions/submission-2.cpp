class Solution {
public:
    void solve2(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> grid = board;
        bool flag=true;
        q.push({i,j});
        grid[i][j] = 'X';
        visited[i][j]=true;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            auto top = q.front();
            int x = top.first, y = top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny=y+dy[k];
                if(nx<0||ny<0||nx>=n||ny>=m){
                    flag=false;
                    continue;
                }
                if(!visited[nx][ny]&&grid[nx][ny]=='O'){
                    grid[nx][ny]='X';
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        if(flag){
            board=grid;
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!visited[i][j]) solve2(board,i,j,visited);
            }
        }
    }
};
