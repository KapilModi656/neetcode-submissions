class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int j=n;
        vector<int> nums=arr;
        for(int i=0;i<n;i++){
            if(arr[i]>=x){
                j=i;
                break;
            }
        }
        int l=j-1;
        int r=j;
        vector<int> ans;
        while(k>0){
            if(r>=n){
                k--;
                ans.push_back(nums[l]);
                l--;
            }
            else if(l<0){
                k--;
                ans.push_back(nums[r]);
                r++;
            }
            else{
                int d1=abs(nums[r]-x);
                int d2=abs(nums[l]-x);
                if(d1>=d2){
                    k--;
                    ans.push_back(nums[l]);
                    l--;
                }
                else{
                    k--;
                    ans.push_back(nums[r]);
                    r++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};