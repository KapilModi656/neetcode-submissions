class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        
        vector<bool> prev(n,false);
        int count=0;
        for(int i=n-1;i>=0;i--){
            vector<bool> curr(n,false);
            for(int j=i;j<n;j++){
                if(i==j) {
                    count++;
                    curr[j]=true;
                    continue;
                }
                else if(s[i]==s[j]){
                    if(i+1==j){
                        curr[j]=true;
                    }
                    else{
                        curr[j] = prev[j-1];
                    }
                    if(curr[j]==true){
                        count++;
                    }
                }
            }
            swap(prev,curr);
        }
        
        return count;
    }
};
