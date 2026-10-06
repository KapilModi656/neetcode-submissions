class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0),right(n,0);
        int maxi=height[0];
        left[0]=height[0],right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            if(maxi>height[i]) left[i]=maxi;
            else maxi=height[i],left[i]=height[i];
        }
        maxi=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi>height[i]) right[i]=maxi;
            else maxi=height[i],right[i]=height[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= abs(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};
