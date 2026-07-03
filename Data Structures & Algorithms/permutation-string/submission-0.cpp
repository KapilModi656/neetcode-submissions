class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        vector<int> ans(26,0);
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            freq[s1[i]-'a']++;
            ans[s2[i]-'a']++;
        }
        if(freq==ans) return true;
        int l=0;
        int r=n;
        while(r<m){
            ans[s2[r]-'a']++;
            ans[s2[l]-'a']--;
            if(freq==ans) return true;
            l++;
            r++;
        }
        return false;
    }
};
