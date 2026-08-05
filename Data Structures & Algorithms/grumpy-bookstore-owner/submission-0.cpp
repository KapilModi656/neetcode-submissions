class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) ans+=customers[i];
        }
        int e=minutes-1;
        int diff = 0;
        int maxi=0;
        for(int i=0;i<=e;i++) {
            if(grumpy[i]==1) diff+=customers[i];
        }
        maxi = max(maxi,diff);
        for(int i=e+1;i<n;i++){
            if(grumpy[i-minutes]==1) diff-=customers[i-minutes];
            if(grumpy[i]==1) diff += customers[i];
            maxi = max(maxi,diff);
        }
        return ans+maxi;
    }
};