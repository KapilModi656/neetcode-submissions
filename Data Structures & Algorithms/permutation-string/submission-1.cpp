class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        int n=s1.size(),m=s2.size();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            count[s2[i]-'a']--;
        }
        bool flag=true;
        for(int i=0;i<26;i++) if(count[i]!=0) flag=false;
        if(flag) return true;
        for(int i=n;i<m;i++){
            count[s2[i-n]-'a']++;
            count[s2[i]-'a']--;
            flag=true;
            for(int i=0;i<26;i++) if(count[i]!=0) flag=false;
            if(flag) return true;
        }
        return false;
    }
};
