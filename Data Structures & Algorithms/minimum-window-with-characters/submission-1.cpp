class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> count;
        int n=s.size();
        int mini=INT_MAX;
        
        string st="";
        for(int i=0;i<t.size();i++) count[t[i]]++;
        int l=0;
        int i=0;
        for(int r=0;r<n;r++){
            count[s[r]]--;
            bool flag=true;
            for(auto it:count){
                if(it.second>0) flag=false;
            }
            while(flag){
                if(r-l+1<mini){
                    mini=r-l+1;
                    i=l;
                }
                count[s[l]]++;
                for(auto it:count){
                    if(it.second>0) flag=false;
                }
                l++;
            }
        }
        if(mini!=INT_MAX){
            for(int j=i;j<i+mini;j++){
                st+=s[j];
            }
        }
        return st;
    }
};
