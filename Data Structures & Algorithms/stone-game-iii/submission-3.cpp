class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n=stone.size();
        vector<int> dp(n+1,INT_MIN);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int score1 = stone[i]-dp[i+1];
            int score2=INT_MIN;
            int score3=INT_MIN;
            if(i+1<n){
                score2 = stone[i]+stone[i+1]-dp[i+2];
            }
            if(i+2<n){
                score3 = stone[i]+stone[i+1]+stone[i+2]-dp[i+3];
            }
            dp[i] = max({score1,score2,score3});
        } 
        if(dp[0]>0){
            return "Alice";
        }
        else if(dp[0]==0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};