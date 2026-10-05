class Solution {
public:
    char lowercase(char a){
        if(a>='A'&&a<='Z') return a-'A'+'a';
        return a;
    }
    bool isPalindrome(string s) {
        string t="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(('A'<=s[i]&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||
            (s[i]>='0'&&s[i]<='9')){
                t+=lowercase(s[i]);
            }
        }
        int i=0;
        int m=t.size();
        while(i<m-i-1){
            if(t[i]!=t[m-i-1]) return false;
            i++;
        }
        return true;
    }
};
