class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        int max_len=1;
        int start=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(i+1==j){
                        dp[i][j]=true;
                    }
                    else dp[i][j] = dp[i+1][j-1];
                    if(dp[i][j]){
                        if(max_len<j-i+1){
                            max_len = j-i+1;
                            start=i;
                        }
                    }
                }
            }
        }
        return s.substr(start,max_len);

    }
};
