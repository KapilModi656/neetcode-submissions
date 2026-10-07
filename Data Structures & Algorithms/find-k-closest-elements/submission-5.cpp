class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int r=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=r-1;
        vector<int> ans;
        if(l==-1){
            for(int i=0;i<k;i++) ans.push_back(arr[i]);
            return ans;
        }
        else if(r==n){
            for(int i=n-1;i>n-k-1;i--) ans.push_back(arr[i]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
        while(k&&l>=0&&r<n){
            if(abs(arr[l]-x)>abs(arr[r]-x)){
                ans.push_back(arr[r]);
                r++;
                k--;
            }
            else{
                ans.push_back(arr[l]);
                l--;
                k--;
            }
        }
        if(l==-1){
            for(int i=r;i<r+k;i++) ans.push_back(arr[i]);
         
        }
        else if(r==n){
            for(int i=l;i>l-k;i--) ans.push_back(arr[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};