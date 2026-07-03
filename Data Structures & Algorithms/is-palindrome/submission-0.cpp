class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string a="";
        for(int i=0;i<n;i++){
            if(s[i]>='A'&&s[i]<='Z') s[i]=tolower(s[i]);
        }
        for(int i=0;i<n;i++){
            if((s[i]<='z'&&s[i]>='a')||(s[i]>='0'&&s[i]<='9')) a+=s[i];
        }
        int m=a.size();
        int i=0;
        int j=m-1;
        while(i<=j){
            if(a[i]!=a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
