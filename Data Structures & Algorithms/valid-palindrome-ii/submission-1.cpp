class Solution {
public:
    bool check(string s){
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
       
        return true;
    }
    bool validPalindrome(string s) {
        if(check(s)) return true;
        for(int i=0;i<s.size();i++){
            string a=s;
            a.erase(i,1);
            if(check(a)) return true;
        }
        return false;
        
    }
};