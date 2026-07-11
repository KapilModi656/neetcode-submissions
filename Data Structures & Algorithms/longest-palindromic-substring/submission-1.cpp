class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++) dp[i][i]=true;
        int st=0;
        int end=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j) continue;
                if(s[i]==s[j]){
                    if(i+1==j){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j]==true){
                        if(end-st+1<j-i+1){
                            end=j;
                            st=i;
                        }
                    }
                }
            }
        }
        
        return s.substr(st, end - st + 1);;
    }
};
