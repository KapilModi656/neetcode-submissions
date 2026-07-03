class Solution {
public:
    bool check(vector<int>& arr,vector<int>& temp){
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(temp[i]>0){
                if(temp[i]>arr[i]){
                    return false;
                }
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> temp(128,0);
        vector<int> arr(128,0);
        int m=t.size();
        int n=s.size();
        for(int i=0;i<m;i++){
            temp[t[i]-'A']++;
        }
        
        int r=-1;
        int l=0;
    
        for(int i=0;i<n;i++){
            arr[s[i]-'A']++;
            if(check(arr,temp)){
                r=i;
                break;
            }
        }
        if(r==-1) return "";
        int mini=r-l+1;
      
        int i=l;
        int j=r;
        while(l<n){
            arr[s[l]-'A']--;
            l++;
            while(r<n&&!check(arr,temp)){
                r++;
                if(r<n) arr[s[r]-'A']++;  
            }
            if(check(arr,temp)&&r-l+1<mini){
                i=l;
                j=r;
                mini=r-l+1;
            }
        }
        string ans="";
        for(int k=i;k<=j;k++){
            ans+=s[k];
        }
        return ans;
    }
};
