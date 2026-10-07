class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(n,0);
        prev[n-1]=-1;
        int curr=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]<=curr){
                prev[i]=curr;
            }
            else{
                prev[i]=-1;
                curr=prices[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prev[i]==-1) continue;
            ans=max(ans,prev[i]-prices[i]);
        }
        return ans;
    }
};
